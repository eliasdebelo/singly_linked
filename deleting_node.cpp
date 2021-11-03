#include <iostream>
using namespace std;

struct Node{
	int value;
	struct Node *next;
};

void addAtEnd(Node *head, int x)
{
	Node *temp = new Node;
	temp->value = x;
	temp->next = NULL; //because it is always at the end
	//Lets go to the end of the list
	Node *p = head; //starting from the head to ..
	while (p->next != NULL)
		p = p->next;
	//now append
	p->next = temp;
}

void display(Node *head)
{
	Node *ptr = head; //starting from the head to ..
	while (ptr != NULL)
	{
		cout<<ptr->value<<"  ";
		ptr = ptr->next;	
	}
	cout<<endl;
}

Node* deleteFromBegining(Node *head)
{
	Node *temp = head;
	//then
	head = head->next; //move your head pointer to the next node
	//delete the previous head, which is temp
	delete temp;
	
	return head;
}

void deleteFromEnd(Node *head)
{
	//we need to go to the end of the list
	Node *ptr1 = head;
	Node*ptr2;
	
	while (ptr1->next != NULL)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;	
	}
	//we have reached the end, where ptr1->next = NULL
	//now update end of list as:
	ptr2->next = NULL;
	//Then clear your memory
	delete ptr1;	
}

void deleteFromMiddle(Node *head, int x)
{
	Node *ptr2;
	Node *ptr1 = head;
	//	
	while (ptr1->value != x)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;	
	}	
	//
	ptr2->next = ptr1->next;
	//now safely remove ptr2 from the middle
	delete ptr1;
}

int main(int argc, char** argv) 
{
	//Head is always pointing to the root node in the list
	struct Node *head = new Node;
	head->value = 2;
	head->next = NULL; 
	//
	for (int i=4; i<=10;){
		addAtEnd(head, i);	
		i += 2;
	}
	//
	display(head);
	//
	head = deleteFromBegining(head);	
	display(head);
	//
	deleteFromEnd(head);
	display(head);
	//
	deleteFromMiddle(head, 6);
	/*
		Mind here: You can delete now at certain index or delete node with certain value.
		Lets do the latter
	*/
	display(head);
	//
	
	return 0;
}
