#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

struct Node* getnode(x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
};

void Print()
{
    struct Node* print_node = head;
    printf("The list is: ");
    while(print_node!=NULL)
    {
        printf("%d ",print_node->data);
        print_node = print_node->next;
    }
    printf("\n");
}

void push()
{
    int x;
    printf("Enter the element: ");
    scanf("%d",&x);
    struct Node* new_node = getnode(x);
    if(head == NULL)
    {
        head = new_node;
        Print();
        return;
    }
    struct Node* previ_node = head;
    while(previ_node->next!=NULL)
        previ_node = previ_node->next;
    previ_node->next = new_node;
    Print();
}

void pop()
{
    if(head == NULL)
    {
        printf("----UNDERFLOW DETECTED----");
        return;
    }
    struct Node* previ_node = head;
    if(previ_node->next == NULL)
    {
        free(previ_node);
        printf("List is empty\n");
        return;
    }
    while(previ_node->next->next!=NULL)
        previ_node = previ_node->next;
    struct Node* del_node = previ_node->next;
    previ_node->next = NULL;
    free(del_node);
    Print();
}

int main()
{
    head=NULL;
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
