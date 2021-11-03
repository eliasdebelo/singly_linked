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
	//
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

Node* addAtBegining(Node *head, int x)
{
	Node *newHead = new Node;
	newHead->value = x;
	//
	newHead->next = head;	
	head = newHead;
	//
	return head;	//return the updated
}

void addAtMiddle(Node *head, int x)
{
	Node *temp = new Node;
	temp->value = x;
	//
	Node *ptr2;
	Node *ptr1 = head;	
	
	while (ptr1->value < x)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;	//ptr1 is always ahead of ptr2
	}
	//We need to insert temp  between ptr1 and ptr2
	temp->next = ptr1;
	ptr2->next = temp;
	//Don't forget head is still refering to the root of the list
}

void insertAtMiddle(Node *head, int index, int val)
{
	int count = 0;
	Node *temp = new Node;
	temp->value = val;
	//Find the index
	Node *ptr1 = head;
	Node *ptr2;
	
	while (count < index)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
		count++;
	}
	//here, we have reached at index
	temp->next = ptr1;
	ptr2->next = temp;
}
int main(int argc, char** argv) 
{
	//Head is always pointing to the root node in the list
	struct Node *head = new Node;
	head->value = 2;
	head->next = NULL; //next node to the head is NULL, because it is the begining for now.
	//
	for (int i=4; i<=10;){
		addAtEnd(head, i);	//i is going to be added to a list	
		i += 2;
	}
	
	display(head);	

	//Now lets add element to the begining (update the head to new node)
	head = addAtBegining(head, 1);
	//
	display(head);	//display new list
	
	/*How to add node to middle of the list. 
	We have 1  2  4  6  8  10 nodes in the list. 
	We can use index or other condition to insert 
		I will insert 3 between 2 and 4. */
	
	//addAtMiddle(head, 3);
	
	insertAtMiddle(head, 2, 3);
	//
	display(head);
	/*
		Question: insert new node at index 3. Not by comparing values but by counting indexes
	*/
	
	return 0;
}
