#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * prev;
    struct node * link;
}*start, *end;

void createList(int n);
void displayList();
void reverseList();

int main()
{
    int n, data, choice;
    start=NULL;
    end=NULL;
    while(1)
    {
        printf("1. Create List\n");
        printf("2. Reverse List\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                reverseList();
                break;
            case 3:
                displayList();
                break;
            case 4:
		exit(0);
                break;
            default:
                printf("Invalid choice please choose between 1-4");
        }
    }
    return 0;
}

void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        start=(struct node *)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d", &data);
        start->data=data;
        start->prev=NULL;
        start->link=NULL;
        end=start;
	for(i=2;i<=n;i++)
        {
            newNode=(struct node *)malloc(sizeof(struct node));
            printf("Enter data\n");
            scanf("%d", &data);
            newNode->data=data;
            newNode->prev=end; 
            newNode->link=NULL;
            end->link=newNode; 
            end=newNode;
        }
    }
}

void displayList()
{
    struct node * temp;
    int n=1;

    if(start==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp=start;
        printf("list is:\n");
        while(temp!=NULL)
        {
            printf("data is %d\n",temp->data);
            n++;
            temp=temp->link;
        }
    }
}

void reverseList()
{
    struct node *current, *temp;
    current=start;
    while(current!=NULL)
    {
        temp=current->link;
        current->link=current->prev;
        current->prev=temp;
        current=temp;
    }
    temp=start;
    start=end;
    end=temp;
    printf("list is reversed\n");
}
