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
struct sll
{
	public:
	Node *head;
	sll()
	{
		head=NULL;
	}
		
	void insertAtBeg(int data)
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
	void display()
	{
		Node *current=head;
		while(current!=NULL)
		{
			cout<<current->info<<" ";
			current=current->next;
		}
	}
	//this compares each ele of two LL and merge to final sorted LL 
	Node *merge_sort(Node *first,Node *second)
	{
		Node *final_L;
		Node *temp;
		final_L=temp;
		//untill any LL becomes empty
		while(first!=NULL && second!=NULL)
		{
			if(first->info <= second->info)
			{
				temp->next=first;
				first=first->next;
			}
			else
			{
				temp->next=second;
				second=second->next;
			}
			temp=temp->next;
		}
		//if second LL is empty
		while(first!=NULL)
		{
			temp->next=first;
			first=first->next;
			temp=temp->next;
		}
		//if first LL is empty
		while(second!=NULL)
		{
			temp->next=second;
			second=second->next;
			temp=temp->next;
		}
		
		return final_L->next;
	}
	//function finds mid of LL
	Node *middle(Node *head)
	{
		Node *slow=head;
		Node *fast=head->next;
		while(slow->next!=NULL &&(fast->next!=NULL && fast!=NULL) )
		{
			slow=slow->next;
			fast=fast->next->next;
		}
		return slow;
	}
	//
	Node *merge(Node *head)
	{
		if(head->next==NULL)
		{
			return head;
		}
		Node *first;
		Node *second;
		
		first=middle(head);
		second=first->next;
		first->next=NULL;
		
		Node *final_L=merge_sort( merge( head ) , merge( second ) ) ;
		return final_L;		
	}	
};

int main()
{
	sll ob1;
//	int m,arr[100];
//	cout<<"\nEnter no. of elements you want to enter in Linked list 1: ";
//	cin>>m;
//	cout<<"\nEnter 1st sorted linked list: ";
//	for(int i=0;i<=m;i++)
//	{
//		cin>>arr[i];
//		ob1.insertAtBeg(arr[i]);
//	}


	ob1.insertAtBeg(2);
	ob1.insertAtBeg(3);
	ob1.insertAtBeg(20);
	ob1.insertAtBeg(5);
	ob1.insertAtBeg(10);
	ob1.insertAtBeg(7);
	
	cout<<"\n LL before sorting : ";
	ob1.display();
	
	cout<<"\n LL after sorting : ";
	ob1.merge(ob1.head);
	ob1.display();
		
	return 0;
}

