#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void push(struct Node** start, int new_data)
{
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=(*start);
	(*start)=new_node;
}

int detectLoop(struct Node* list)
{
	struct Node *slow_p = list, *fast_p = list;
	while (slow_p&&fast_p&&fast_p->next)
       	{
		slow_p=slow_p->next;
		fast_p=fast_p->next->next;
		if (slow_p==fast_p)
	       	{
			return 1;
		}
	}
	return 0;
}

int main()
{
	struct Node* start=NULL;
	push(&start,20);
	push(&start,4);
	push(&start,15);
	push(&start,10);
	/*start->next->next->next->next=start;
	 */
	if (detectLoop(start))
		printf("Loop found\n");
	else
		printf("Loop not found\n");
	return 0;
}

