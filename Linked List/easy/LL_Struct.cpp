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
	void merge(Node )	
};

int main()
{
	sll ob1;
	int m,arr[100];
	cout<<"\nEnter no. of elements you want to enter in Linked list 1: ";
	cin>>m;
	cout<<"\nEnter 1st sorted linked list: ";
	for(int i=0;i<=m;i++)
	{
		cin>>arr[i];
		ob1.insertAtBeg(arr[i]);
	}

	
	
	sll ob2;
	int x,arr2[100];
	cout<<"\nEnter no. of elements you want to enter in Linked list 2: ";
	cin>>x;
	cout<<"\nEnter 2nd sorted linked list:  ";
	for(int i=0;i<x;i++)
	{
		cin>>arr2[i];
		ob2.insertAtBeg(arr2[i]);
	}
	
	cout<<"\nSorted LL 1 : ";
	ob1.display();
	
	cout<<"\nSorted LL 2 : ";
	ob2.display();
	
	return 0;
}
