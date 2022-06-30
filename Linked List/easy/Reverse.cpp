//Revrse a linked list
#include<iostream>
using namespace std;
struct Node
{
	int info;
	struct Node* next;
	Node(int data)
	{
		info=data;
		next=NULL;
	}
};
struct Sll
{
	public: 
	Node *head;
	Sll()
	{
		head=NULL;
	}
	void inserAtBeg(int data)
	{
		Node *temp=new Node(data);
		if(head==NULL)
			head=temp;
		else
		{
			temp->next=head;
			head=temp;
		}
	}
	void reverse()
	{
		Node* current=head;
		Node* prevNode=NULL;
		Node* nextNode=NULL;
		while(current!=NULL)
		{
			nextNode=current->next;
			current->next=prevNode;
			
			prevNode=current;
			current=nextNode;
		}
		head=prevNode;	
	}	
	void display()
	{
		Node * current=head;
		while(current!=NULL)
		{
			cout<<current->info<<" ";
			current=current->next;
		}
	}
};
int main()
{
	Sll ob;
	//ob.inserAtBeg(1);
	ob.inserAtBeg(85);
	ob.inserAtBeg(15);
	ob.inserAtBeg(4);
	ob.inserAtBeg(20);
	cout<<"\nBefore reverse LL : ";
	ob.display();
	cout<<"\nAfter reverse LL : ";
	ob.reverse();
	ob.display();

	return 0;
}
