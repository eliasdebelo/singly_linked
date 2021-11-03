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


void updateNode(Node *head, int oldValue, int newValue)
{
	//we need to go to the end of the list
	Node *ptr = head;
	while (ptr->value != oldValue)
		ptr = ptr->next;	
	//we have found old node with sequential search	
	ptr->value = newValue;//then update
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
	display(head);	//old list
	// Change node value from 6 to 7
	updateNode(head, 6, 7);
	//
	display(head); //new list

	return 0;
}
