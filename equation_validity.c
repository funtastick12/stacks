#include<stdlib.h>
#define MAX 30
#include<stdio.h>
#include<string.h>
 struct stack{
    char str_chr[10];
    int top;
};
struct stack s;

void push(int element){
    if(s.top==MAX-1){
        printf("Overflow!!");
    }
    else{
  s.top++;
  s.str_chr[s.top]=element;
}
}
void pop(){
    if(s.top==-1){
        printf("Underflow!!");
    }
        else{
            
            s.top--;
            
        }
    }


void display(){
    if(s.top==-1){
        printf("Empty stack");
    }
    else{
        printf("\n Stack contents: ");
        for(int i=0;i<=s.top;i++){
            printf("\n%d",s.str_chr[i]);
        }
    }
}
int main()
{
    s.top=-1;
    char str[100];
    printf("Enter the equation");
   scanf("%s",&str);

   int len=strlen(str);

   for(int i=0;i<=len;i++){
    if (str[i]=='('){
        push('(');
    }
    else if (str[i]=='{')
    {
        push('{');
    }
    else if (str[i]=='[')
    {
        push('[');
    }
    
    
    else if ((str[i]==')')&&(s.top>=0)&&(s.str_chr[s.top]=='('))
    {
       pop();
    }
    else if ((str[i]=='}')&&(s.top>=0)&&(s.str_chr[s.top]=='{'))
    {
       pop();
    }
    else if ((str[i]==']')&&(s.top>=0)&&(s.str_chr[s.top]=='['))
    {
       pop();
    }
    else if ((str[i]==')'||str[i]==']'||str[i]=='}')&&s.top==-1)
    {
       printf("Equation not valid");
       exit(1);
    }
    }

   if (s.top==-1){
    printf("Equation valid");
   }
  
   else{
   
   printf("Equation not valid");
   exit(0);
   }
   
   
}

