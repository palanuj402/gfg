struct Node* partition(struct Node* head, int x) 
{
    struct Node *eqh=NULL,*eql=NULL;
    struct Node *leh=NULL,*lel=NULL;
    struct Node *grh=NULL,*grl=NULL;
    while(head!=NULL)
    {
        //agar equal hua x ke 
        if(head->data==x)
        {
            if(eqh==NULL)
                eqh=eql=head;
            else
            {
                eql->next=head;
                eql=eql->next;
            }
        }
        //agar x se less hai toh leh mein 
        else if(head->data < x)
        {
            if(leh==NULL)
                leh=lel=head;
            else
            {
                lel->next=head;
                lel=head;
            }
        }
        //agar x greater hai grh wale mein dalenge
        else
        {
            if(grh=NULL)
                grh=grl=head;
            else
            {
                grl->next=head;
                grl=head;
            }
        }
        head=head->next;
    }
    if(grl!=NULL)
        grl->next=NULL;
    
    //now connect 3 list
    if(leh==NULL)
    {
        //if lesser LL is empty nd equal LL is also empty
        if(eqh==NULL)
            return grh;
        //if lesser LL is empty nd equal LL is NOT empty    
        eql->next=grh;
            return eqh;
    }
    if(eqh==NULL)
    {
        lel->next=grh;
        return leh;
    }
    //if both lesser and equi LL are NOT empty
    lel->next=eqh;
    eql->next=grh;
    return leh;
}
