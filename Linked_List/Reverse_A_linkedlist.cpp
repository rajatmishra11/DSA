#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList()
    {
        head = NULL;
    }

	/* Function to reverse the linked list */
	void reverse()
	{
        //har node ko pakad kar piche point karao-.
        Node *prev=NULL;
        Node *curr=head;
        Node *forward=NULL;


        while(curr!=NULL){ 
            forward=curr->next;
            curr->next=prev;
            prev=curr; 
            curr=forward; 
        }
        head=prev;
	}
    
	/* Function to print linked list */
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void insert(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

/* Driver code*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.insert(20);
	ll.insert(4);
	ll.insert(15);
	ll.insert(85);

	cout << "Given linked list\n";
	ll.print();
    ll.reverse();
	cout << "\nReversed linked list \n";
	ll.print();
	return 0;
}
