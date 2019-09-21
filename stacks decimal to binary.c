#include<stdio.h>
#define SIZE 10
int stack[SIZE];
int top=-1;
int empty();
int full();
void push(int x);
void pop();
void display();
int main()

{
    int n,remainder;
    printf("Enter a decimal number:");
    scanf("%d",&n);
    while(n!=0){
        remainder = n%2;
        n = n/2;
        push(remainder);
    }
    display();
}
int empty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int full(){
    if(top==SIZE){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int x){
    if(full()){
        printf("Stack overflow!!\n");
    }
    else{
        top++;
        stack[top] = x;
    }
}
void pop(){
    if(empty()){
        printf("Stack empty");
    }
    else{
        top--;
    }
}
void display(){
    int i;
    for(i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
}

