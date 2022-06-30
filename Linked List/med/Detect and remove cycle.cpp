//DETECT LOOP IN LINKED LIST AND REMOVE
/*
Method 1:

1. We know that Floyd’s Cycle detection algorithm terminates when fast and slow pointers meet at a common point. 
2. We also know that this common point is one of the loop nodes (2 or 3 or 4 or 5 in the above diagram).
3. Store the address of this in a pointer variable say ptr2.
4. After that start from the head of the Linked List and check for nodes one by one if they are reachable from ptr2. 
5. Whenever we find a node that is reachable,
6. we know that this node is the starting node of the loop in Linked List
   and we can get the pointer to the previous of this node.
*/
// C++ program to detect and remove loop in linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to remove loop. 
Used by detectAndRemoveLoop() */
void removeLoop(struct Node*, struct Node*);

/* This function detects and 
  removes loop in the list
  If loop was there in the 
  list then it returns 1,
  otherwise returns 0 */
int detectAndRemoveLoop(struct Node* list)
{
    struct Node *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next) 
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        /* If slow_p and fast_p meet at 
            some point then
           there is a loop */
        if (slow_p == fast_p) {
            removeLoop(slow_p, list);

            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }

    /* Return 0 to indeciate that ther is no loop*/
    return 0;
}

/* Function to remove loop.
 loop_node --> Pointer to 
 one of the loop nodes
 head -->  Pointer to the 
 start node of the linked list */
void removeLoop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr1;
    struct Node* ptr2;

    /* Set a pointer to the beginning 
      of the Linked List and
      move it one by one to find the 
      first node which is
      part of the Linked List */
    ptr1 = head;
    while (1) {
        /* Now start a pointer from 
        loop_node and check if
       it ever reaches ptr2 */
        ptr2 = loop_node;
        while (ptr2->next != loop_node
               && ptr2->next != ptr1)
            ptr2 = ptr2->next;

        /* If ptr2 reahced ptr1 
        then there is a loop. So
        break the loop */
        if (ptr2->next == ptr1)
            break;

        /* If ptr2 did't reach ptr1 
         then try the next node
         * after ptr1 */
        ptr1 = ptr1->next;
    }

    /* After the end of loop ptr2
     is the last node of the
     loop. So make next of ptr2 as NULL */
    ptr2->next = NULL;
}

/* Function to print linked list */
void printList(struct Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

struct Node* newNode(int key)
{
    struct Node* temp = new Node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}

// Driver Code
int main()
{
    struct Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    cout << "Linked List after removing loop" << endl;

    printList(head);

    return 0;
}

//METHOD -2
/*

1. This method is also dependent on Floyd's Cycle detection algorithm.
2. Detect Loop using Floyd's Cycle detection algorithm and get the pointer to a loop node.
3. Count the number of nodes in loop. Let the count be k.
4. Fix one pointer to the head and another to a kth node from the head.
5. Move both pointers at the same pace, they will meet at loop starting node.
6. Get a pointer to the last node of the loop and make next of it as NULL.
*/

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to remove loop. */
void removeLoop(struct Node*, struct Node*);

/* This function detects and removes loop in the list
  If loop was there in the list then it returns 1,
  otherwise returns 0 */
int detectAndRemoveLoop(struct Node* list)
{
    struct Node *slow_p = list, *fast_p = list;

    // Iterate and find if loop exists or not
    while (slow_p!=NULL && fast_p!=NULL && fast_p->next!=NULL) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p) {
            removeLoop(slow_p, list);

            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }

    /* Return 0 to indicate that there is no loop*/
    return 0;
}

/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr1 = loop_node;
    struct Node* ptr2 = loop_node;

    // Count the number of nodes in loop
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }

    // Fix one pointer to head
    ptr1 = head;

    // And the other pointer to k nodes after head
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;

    /*  Move both pointers at the same pace,
      they will meet at loop starting node */
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Get pointer to the last node
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;

    /* Set the next node of the loop ending node
      to fix the loop */
    ptr2->next = NULL;
}

/* Function to print linked list */
void printList(struct Node* node)
{
    // Print the list after loop removal
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

struct Node* newNode(int key)
{
    struct Node* temp = new Node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}

// Driver Code
int main()
{
    struct Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    cout << "Linked List after removing loop \n";
    printList(head);
    return 0;
}




// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


 // } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if(head==NULL || head->next==NULL)
        return;
        Node *slow=head;
        Node *fast=head;
        bool isCycle=false;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                isCycle=true;
                break;
            }
        }
        if(isCycle)
        {
            if(slow==head)
            {
                while(slow->next!=fast)
                {
                    slow=slow->next;
                }
                slow->next=NULL;
            }
            else
            {
                fast=head;
                while(fast->next!=slow->next)
                {
                    fast=fast->next;
                    slow=slow->next;
                }
                slow->next=NULL;
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
  // } Driver Code Ends
  
  
