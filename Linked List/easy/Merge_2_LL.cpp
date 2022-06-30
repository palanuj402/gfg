#include<iostream>
using namespace std;

struct Node
{
	int info;
	struct Node *next;
	Node(int data)
	{
		info=data;
		next=NULL;
	}	
};
class Try
{
	Node *head;
	public:
	Try()
	{
		head=NULL;
	}
	void insertAtEnd(int data)
	{
		Node *temp=new Node(data);
		Node *current=head;
		if(head==NULL)
			head=temp;
		else
		{
			while(current!=NULL)
				current=current->next;			
			current->next=temp;
			current=temp;
			 
		}			
	}
	void display()
	{
		Node *current=head;
		cout<<"\nLL is: ";
		while(current!=NULL)
		{
			cout<<current->info<<" ";
			current=current->next;		
		}
	}	
};
int main()
{
	Try ob;
	ob.insertAtEnd(5);
	ob.insertAtEnd(6);
	ob.insertAtEnd(8);
	ob.insertAtEnd(9);
	ob.insertAtEnd(10);
	ob.display();
	
	return 0;
}
