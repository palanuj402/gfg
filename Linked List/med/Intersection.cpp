/*
Method-->1  (Naive soln)
1. Use 2 nested for loops. The outer loop will be for each node of the 1st list and inner loop will be for 2nd list. 
2. In the inner loop, check if any of nodes of the 2nd list is same as the current node of the first linked list. 
The time complexity of this method will be O(M * N) where m and n are the numbers of nodes in two lists.

Method-->2
This solution requires modifications to linked list data structure. Have a visited flag with each node. Traverse the first linked list and keep marking visited nodes. 
Now traverse the second linked list, If you see a visited node again then there is an intersection point, return the intersecting node. 
This solution works in O(m+n) but requires additional information with each node. 
A variation of this solutionbasic  that doesn’t require modification to the basic data structure can be implemented using a hash. 
Traverse the first linked list and store the addresses of visited nodes in a hash. 
Now traverse the second linked list and if you see an address that already exists in the hash then return the intersecting node.


Method-->3
1. Get count of the nodes in the first list, let count be c1.
2. Get count of the nodes in the second list, let count be c2.
3. Get the difference of counts d = abs(c1 – c2)
4. Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes
5. Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)
*/
//func to find num of nodes
int getCount(Node *head)
{
    int count=0;
    Node *c1=head;
    while(c1!=NULL)
    {
        count++;
        c1=c1->next;
    }
    return count;
}
//func to find intersection
int f(int d,Node *head1,Node *head2)
{
    Node *c1=head1;
    Node *c2=head2;
    
    for(int i=0;i<d;i++)
    {
        if(c1==NULL)
            return -1;
        c1=c1->next;    
    }
    while(c1!=NULL && c2!=NULL)
    {
        if(c1==c2)
            return c1->data;
            
        c1=c1->next;
        c2=c2->next;
    }
    return -1;
}
//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int x=getCount(head1);
    int y=getCount(head2);
    int d;
    if(x>y)
    {
        d=x-y;
        return f(d,head1,head2);
    }
    else
    {
        d=y-x;
        return f(d,head2,head1);
    }
    
}
