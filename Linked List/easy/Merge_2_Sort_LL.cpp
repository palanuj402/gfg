Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    if((head1->data)<(head2->data) )
    {
        head1->next=sortedMerge(head1->next,head2);
        return head1;
    }
    else
    {
        head2->next=sortedMerge(head1,head2->next);
        return head2;
    }
}




// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//we are doing in place merge sort 
//time complexity-O(n+m)
//space complexity -O(1)
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    //if first LL is empty return head of 2nd ll
    if(head1==NULL)
        return head2;
    //if second LL is empty return head of 1st ll    
    if(head2==NULL)
        return head1;
    //if first node of 1st ll is greater
    //than 1st node of 2nd LL then swap    
    if(head1->data > head2->data)
        swap(head1,head2);
   	//this is our answer pointing to head1
	   //we will return it as answer 
    Node *ans=head1;
    //iterate till both the LL will be empty
    while(head1!=NULL && head2!=NULL)
    {
        Node *temp=NULL;
        //iterate till head1 is less than head2
        while(head1!=NULL && head1->data<=head2->data)
        {
            temp=head1;
            head1=head1->next;
        }
        temp->next=head2;
        swap(head1,head2);
    }
    //simply return answer
    return ans;
}  

