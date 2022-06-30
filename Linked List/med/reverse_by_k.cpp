class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        //sabse pehle current node mein head 
        struct node *current=head;
        //prev mein hi reverse LL aayegi
        struct node *prev=NULL;
        
        stack<node*>s1;
        
        while(current!=NULL)
        {
            int count=0;
            while(count<k && current!=NULL)
            {
                s1.push(current);
                current=current->next;
                count++;
            }
            while(s1.size()>0)
            {
                if(prev==NULL)
                {
                    prev=s1.top();
                    head=prev;
                    s1.pop();
                }
                else
                {
                    prev->next=s1.top();
                    prev=prev->next;
                    s1.pop();
                }    
            }
        }
        prev->next=NULL;
        
        return head;
    }
};

