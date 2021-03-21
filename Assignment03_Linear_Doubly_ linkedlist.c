//Doubly linked list implementation
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head;	//Global declaration of node

struct Node* newNode(x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

int count()
{
    struct Node* curr = head;
    int c=0;
    while(curr!=NULL)
    {
        c++;
        curr = curr->next;
    }
    return c;
}

void Print()
{
	struct Node* temp_print = head;
	printf("\nThe list is: ");
	while(temp_print!=NULL)
	{
		printf("%d ",temp_print->data);
		temp_print = temp_print->next;
	}
	printf("\n");
}

void InsertHead()
{
    int x;
    printf("Enter the value: ");
    scanf("%d",&x);
	struct Node* new_node = newNode(x);
	if(head == NULL)
	{
		head = new_node;
		Print();
		return;
	}
	head->prev = new_node;
	new_node->next = head;
	head = new_node;
	Print();
}

void Insert()
{
    int x,n;
    printf("Enter the value: ");
    scanf("%d",&x);
    printf("Enter the position: ");
    scanf("%d",&n);
    int c = count();
	if(n<=0 || n>=c+2)
	{
		printf("\nError! Invalid position");
		return;
	}
	struct Node* new_node = newNode(x);
	if(n==1)
    {
        new_node->next = head;
        head = new_node;
        Print();
        return;
    }
    struct Node* previ_node = head;
    for(int i=0;i<n-2;i++)
        previ_node = previ_node->next;
    new_node->next = previ_node->next;
    previ_node->next = new_node;
    new_node->prev = previ_node;
    if(new_node->next!=NULL)
        new_node->next->prev = new_node;
    Print();
    return;
}

void InsertTail()
{
    int x;
    printf("Enter the value: ");
    scanf("%d",&x);
    struct Node* new_node = newNode(x);
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
    new_node->prev = previ_node;
    Print();
    return;
}

void Delete()
{
    int n;
    printf("Enter the position: ");
    scanf("%d",&n);
    int c = count();
    if(c==0)
    {
        printf("---------UNDERFLOW DETECTED--------\n");
        return;
    }
	if(n<=0 || n>c)
	{
	    printf("%d\n",c);
		printf("\nError! Invalid position");
		return;
	}
	struct Node* del_node = head;
	if(n==1)
    {
        head = del_node->next;
        free(del_node);
        if(c==1)
        {
            printf("LIST IS EMPTY!!\n");
            return;
        }
        Print();
        return;
    }
    for(int j=0;j<n-2;j++)
        del_node = del_node->next;
    struct Node* del_node1 = del_node->next;
    del_node->next = del_node1->next;
    if(del_node1->next!=NULL)
        del_node1->next->prev = del_node;
    free(del_node1);
    if(c==1)
    {
        printf("LIST IS EMPTY!!\n");
        return;
    }
    Print();
}

int main()
{
	head = NULL;
	int choose,c=1;
	while(c==1)
    {
        printf("Enter 1 for inserting an element at the beginning\nEnter 2 for inserting at any position\nEnter 3 for inserting at end\nEnter 4 for deleting an element");
        printf("\nEnter your choice: ");
        scanf("%d",&choose);
        if(choose == 1)
            InsertHead();
        else if(choose == 2)
            Insert();
        else if(choose == 3)
            InsertTail();
        else if(choose == 4)
            Delete();
        else
            printf("Enter valid choice\n");
        printf("\nEnter 1 to continue and 0 to exit");
        printf("\nDo you want to continue?: ");
        scanf("%d",&c);
    }
}
