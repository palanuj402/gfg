//check if ll is pallindrome or not
//#include<iostream>
//#include<stack>
//using namespace std;
//struct Node
//{
//	int info;
//	struct Node* next;
//	Node(int data)
//	{
//		info=data;
//		next=NULL;
//	}
//};
//struct Sll
//{
//	public: 
//	Node *head;
//	Sll()
//	{
//		head=NULL;
//	}
//	void inserAtBeg(int data)
//	{
//		Node *temp=new Node(data);
//		if(head==NULL)
//			head=temp;
//		else
//		{
//			temp->next=head;
//			head=temp;
//		}
//	}
	//function to check pallindrome
	bool isPallindrome(Node *head)
	{
		stack<int> s;
		Node *current=head;
		while(current!=NULL)
		{
			s.push(current->info);
			current=current->next;
		}
		while(head!=NULL)
		{
			int x=s.top();
			s.pop();
			if(head->info==x)
				head=head->next;
			else
				return false;	
		}
		return true;
	}	
//	void display()
//	{
//		Node * current=head;
//		while(current!=NULL)
//		{
//			cout<<current->info<<" ";
//			current=current->next;
//		}
//	}
//};
int main()
{
//	Sll ob;
//	//ob.inserAtBeg(1);
//	ob.inserAtBeg(85);
//	ob.inserAtBeg(15);
//	ob.inserAtBeg(4);
//	ob.inserAtBeg(20);
//	bool check=ob.isPallindrome()

	return 0;
}
