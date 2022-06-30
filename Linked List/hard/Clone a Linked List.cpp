Node *copyList(Node *head)
{
    //1. first create copy nodes in LL
    Node *c=head;
    Node *font=head;
    while(c!=NULL)
    {
        font=c->next;
        //create duplicate node
        Node *copy=new Node(c->data);
        
        c->next=copy;
        copy->next=font;
        
        c=font;
    }
    //2. assign random pointer to duplicate nodes
    c=head;
    while(c!=NULL)
    {
        if(c->arb!=NULL)
        {
            c->next->arb=c->arb->next;    
        }
        c=c->next->next;    
    }
    //3. separate two LL 
    c=head;
    Node *dum=new Node(0);
    Node *t=dum;
    while(c!=NULL)
    {
        font=c->next->next;
        
        //extract copied node
        t->next=c->next;
        
        //original
        c->next=font;
        
        t=t->next;
        c=font;
    }
    return dum->next;

}
