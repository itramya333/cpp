#include<iostream>
using namespace std;

typedef struct Node{
	int data;
	Node * next;
}node;

// only for the 1st Node
void initNode(node *head, int n){
	head->data = n;
	head->next =NULL;
}

void addNode(node *head, int n)
{
node *NewNode = new node();
NewNode->data = n;
NewNode->next = NULL;
node *cur = head;
while(cur != NULL)
{
	if(cur->next == NULL){
	
	cur->next = NewNode;
	return;
	}
	else
	cur = cur->next;
}
	
}

void reverseNode(node **head)
{
 node *prev = *head;
 node *cur	= prev->next;
 node *ptr2 = cur->next;
 //Prev made to last
 prev->next = NULL;
 while(ptr2)
 {
 	cur->next = prev;
 	prev = cur;
 	cur = ptr2;
 	ptr2 = ptr2->next;
 }
 
 cur->next = prev;
 *head = cur;
}
void reverseRecursion(node **head)
{
	if (*head == NULL)
	return;//empty list
	node *first = *head;
	node *rest = first->next;
	if(rest == NULL)
	return;//only one element
	
	reverseRecursion(&rest);

	first->next->next = first;
	first->next = NULL;
	*head = rest;
}
void displayNode(node * head)
{
	node * list = new node();
	list = head;
	
	while(list)
	{
		cout <<list->data<<" ";
		list = list->next;
	}
	cout <<endl;
}
int main()
{
	struct Node *head = new Node();
	initNode(head, 10);
	//displayNode(head);
	addNode(head, 20);
	addNode(head, 30);
	addNode(head, 40);
	//displayNode(head);
//	reverseNode(&head);
	reverseRecursion(&head);
	displayNode(head);
	return 0;
}
