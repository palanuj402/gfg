//Node *flatten(Node *root)
//{
//	Node *current=root;
//   Node *current2=root;
//   while(current!=NULL && current2!=NULL)
//   {
//       current=current->next;
//       current2=current2->bottom;
//       if(current->data<current2->data)
//       {
//           current->next=current2;
//           current=current2;
//       }
//       else
//       {
//           current2->next=current;
//           current2=current;
//       }
//   }
//   return root;
//        
//}
//

   
   
   
   
//to merge from last 
Node* mergeT(Node *a,Node *b)
{
    Node *temp=new Node(0);
    Node *c=temp;
    while(a!=NULL && b!=NULL)
    {
        if(a->data < b->data)
        {
            temp->bottom=a;
            temp=temp->bottom;
            a=a->bottom;
        }
        else
        {
            temp->bottom=b;
            temp=temp->bottom;
            b=b->bottom;
        }
    }
    //agar a mein abhi bhi nodes hain
    if(a)
        temp->bottom=a;
    else
        temp->bottom=b;
    
    return c->bottom;    
}
/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
	//base condition
    if(root==NULL || root->next==NULL)
        return root;
    //recursively call
    root->next=flatten(root->next);
    //and then merge
    root=mergeT(root,root->next);
    
    return root;
        
}
   
   
   
   
