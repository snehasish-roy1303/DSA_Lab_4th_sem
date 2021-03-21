#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10000
int A[MAXSIZE];
int top = -1;

void Print()
{
    printf("The stack is ");
    if(top==-1)
        printf("empty");
    for(int i=top;i>=0;i--)
        printf("%d ",A[i]);
}

void push()
{
    int x;
    printf("Enter the element: ");
    scanf("%d",&x);
    if(top == MAXSIZE-1)
    {
        printf("----OVERFLOW DETECTED---");
        return;
    }
    A[++top] = x;
    Print();
}

void pop()
{
    if(top == -1)
    {
        printf("---UNDERFLOW DETECTED---");
        return;
    }
    top = top-1;
    printf("First element popped out\n");
    Print();
}

int main()
{
    int n,choice,c=1;
	while(c==1)
    {
        printf("Enter 1 to push element and 0 to pop from the stack\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice == 1)
            push();
        else if(choice == 0)
            pop();
        else
            printf("Enter valid choice\n");
        printf("\nEnter 1 to continue and 0 to exit");
        printf("\nDo you want to continue?: ");
        scanf("%d",&c);
    }
}
