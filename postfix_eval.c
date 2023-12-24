#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

struct stack {
    int str_chr[20];  
    int top;
};
struct stack s;

void push(char element) {
    s.str_chr[++s.top] = element; 
}

int pop() {
    return(s.str_chr[s.top--]);
   
}

void sum() {
    int res, op1, op2;
    op2 = pop();
    op1 = pop();
    res = op1 + op2;
    push(res);
}

void diff() {
    int res, op1, op2;
    op2 = pop();
    op1 = pop();
    res = op1 - op2;
    push(res);
}

void product() {
    int res, op1, op2;
    op2 = pop();
    op1 = pop();
    res = op1 * op2;
    push(res);
}

void division() {
    int res, op1, op2;
    op2 = pop();
    op1 = pop();
    res = op1 / op2;
    push(res);
}

void expo() {
    int res = 1, op1, op2; 
    op2 = pop();
    op1 = pop();
    for (int j = 1; j <= op2; j++) {
        res = op1 * res;
    }
    push(res);
}

int main() {
    s.top = -1;
    char input[100];
    printf("Enter a valid equation \n");
    scanf("%[^\n]s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ') {
            switch (input[i]) {
                case '+':
                    sum();
                    break;

                case '-':
                    diff();
                    break;

                case '*':
                    product();
                    break;

                case '/':
                    division();
                    break;

                case '$':
                    expo();
                    break;

                default:
                    push(input[i] - 48);
            }
        }
    }
    printf("\nThe final result is %d", s.str_chr[s.top]);
    return 0;
}
