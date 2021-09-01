#include <stdio.h>
#include <stdlib.h>

struct node
{
        int info;
        struct node *link;
};
struct node *addatbeg(struct node *start,int data)
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=data;
        temp->link=start;
        start=temp;
        return start;
}

void deleteNode(struct node *node)
{
        struct node *prev;
        if (node==NULL)
                return;
        else
        {
                while (node->link!=NULL)
                {
                        node->data=node->link->data;
                        prev=node;
                        node=node->link;
                }
                prev->link=NULL;
        }
}
struct node *addatend(struct node *start,int data)
{
        struct node *temp,*p;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=data;
        p=start;
        while(p->link!=NULL)
                p=p->link;
        p->link=temp;
        temp->link=NULL;
        return start;
}

struct node *create_list(struct node *start)
{
        int i,n,data;
        printf("enter the number of nodes\n");
        scanf("%d",&n);
        start=NULL;
        if(n==0)
                return start;
        printf("enter the element to be inserted\n");
        scanf("%d",&data);
        start=addatbeg(start,data);
        for(i=2;i<=n;i++)
        {
                printf("enter the element to be inserted\n");
                scanf("%d",&data);
                start=addatend(start,data);
        }
        return start;
}
void display(struct node *start)
{
        struct node *p;
        if(start==NULL)
        {
                printf("list is empty\n");
                return;
        }
        p=start;
        printf("list is\n");
        while(p!=NULL)
        {
                printf("%d\t",p->info);
                p=p->link;
        }
        printf("\n\n");
}

int main()
{
        struct node *start=NULL;
        int choice,data;
        while(1)
        {
                printf("1.add at beginning\n");
                printf("2.add at end\n");
		printf("3.create list\n");
		printf("4.display\n");
		printf("5.node to be deleted whose pointer is given\n");
		printf("6.quit\n");
		printf("enter your choice\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
				printf("enter element to be inserted\n");
                                scanf("%d",&data);
                                start=addatbeg(start,data);
				break;
			case 2:
				printf("enter element to be inserted\n");
                                scanf("%d",&data);
                                start=addatend(start,data);
				break;
			case 3:
                                start=create_list(start);
                                break;
                        case 4:
                                display(start);
                                break;
			case 5:
				deleteNode(start);
				break;
			case 6:
				exit(0);
			default:
				printf("wrong choice\n");
		}
	}
	return 0;
}



