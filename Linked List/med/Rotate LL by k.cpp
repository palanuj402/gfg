Node* rotate(Node* head, int k)
{
    for(int i=0;i<k;i++)
    {
        Node *c=head;
        Node *temp=head;
        while(c!=NULL)
        {
            c=c->next;
        }
        c->next=temp;
        temp=c;
        temp->next=NULL;
        head=head->next;
        
    }
    return head;
}


Node* rotate(Node* head, int k)
{
    if(k==0)
        return NULL;
        
    Node *c=head;
    int count=1;
    
    //pehle current pointer ko kth pos tkk leke aana hai
    while(count<k && c!=NULL )
    {
        c=c->next;
        count++;
    }
    if(c==NULL)
        return NULL;
        
    //now store kth pos in new Node ppointer
    Node *my=c;
    
    //move current to last
    while(c!=NULL)
        c=c->next;
        
    //ab current last node pe hai
    c->next=head;
    
    head=my->next;
    
    my->next=NULL;
        
    return head;    
}



