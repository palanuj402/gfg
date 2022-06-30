//Delete a node
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
struct LL
{
	Node* head=NULL;
	LL()
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
	//when head pointer is given
	int delElement(int x)
	{
		
		Node *current=head->next;
		Node *prevNode=head;
		while(current->info!=x)
		{
			current=current->next;
			prevNode=prevNode->next;
			
		}
		if(current->info==x)
		{
			prevNode->next=current->next;
			delete current;
		}		
	}
	//when head pointer is not given
	void delElement(Node *del)		//Node *del is pointer to which ele in deleted
	{
		if(del==NULL)
			return;
		else
		{
			Node* prev;
			while(del->next!=NULL)
			{
				del->info=del->next->info;
				prev=del;
				del=del->next;
			}
			prev->next=NULL;
		}	
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
	int x;
	LL ob;
	ob.inserAtBeg(1);
	ob.inserAtBeg(3);
	ob.inserAtBeg(5);
	ob.inserAtBeg(4);
	ob.inserAtBeg(7);
	cout<<"\nLL is : ";
	ob.display();
	cout<<"\n Enter value to be deleted: ";
	cin>>x;
	cout<<"\nAfter deletion: ";
	ob.delElement(x);
	ob.display();
	
	return 0;
}
