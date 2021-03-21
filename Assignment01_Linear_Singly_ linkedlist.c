#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node* head;
void Print()
{
	struct Node* print_node = head;
	printf("\nThe list is: ");
	while(print_node!=NULL)
	{
		printf("%d ",print_node->data);
		print_node = print_node->next;
	}
}
void InsertHead()
{
    int x;
    printf("\nEnter the value: ");
    scanf("%d",&x);
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = head;
    head = new_node;
    Print();
}
void InsertTail()
{
    int x;
    printf("Enter the value: ");
    scanf("%d",&x);
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = NULL;
    if(head==NULL){
        head = new_node;
        Print();
    }
    else{
        struct Node* previ_node = head;
        while(previ_node->next!=NULL)
            previ_node=previ_node->next;
        previ_node->next = new_node;
    }
    Print();
}
int count()
{
    int c=0;
    struct Node* curr = head;
    while(curr!=NULL)
    {
        c++;
        curr=curr->next;
    }
    return c;
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
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = x;
	new_node->next=NULL;
	if(n==1)
	{
		new_node->next = head;
		head=new_node;
		Print();
	}
	else
	{
		struct Node* previ_node=head;
		for(int i=0;i<n-2;i++)
			previ_node = previ_node->next;
		previ_node->next = previ_node->next;
		previ_node->next = new_node;
		Print();
	}
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
    int i;
    for(i=0;i<n-2;i++)
        del_node = del_node->next;
    struct Node* del1_node = del_node->next;
    del_node->next =del1_node->next;
    free(del1_node);
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
