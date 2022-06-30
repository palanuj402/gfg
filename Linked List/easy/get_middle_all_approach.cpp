//Find middle element
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
	//Traverse the whole linked list and count the no. of nodes. 
	//Now traverse the list again till count/2 and return the node at count/2.
	int getMiddle()
	{
		int count=0;
		Node* current=head;	
		while(current!=NULL)
		{
			count++;
			current=current->next;
		}
		count=count/2;
		for(int i=0;i<count;i++)
		{
			head=head->next;
		}
		return head->info;
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
	ob.inserAtBeg(1);
	ob.inserAtBeg(85);
	ob.inserAtBeg(15);
	ob.inserAtBeg(4);
	ob.inserAtBeg(20);
	cout<<"\nLL is: ";
	ob.display();
	int mid=ob.getMiddle();
	cout<<"\nMiddle of Linked List is: "<<mid;
	
	return 0;
}
