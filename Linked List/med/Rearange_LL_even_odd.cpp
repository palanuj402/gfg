void rearrangeEvenOdd(Node *head)
{
	Node *even=head->next;
	Node *odd=head;
	Node *evenFirst=even;
	while(1)
	{
	    //agar na toh even bache naa odd bache
	    if(!(odd) || !even || !(even->next))
	    {
	        odd->next=evenFirst;
	        break;
	    }
	    //agar odd yaa even hain toh
	    odd->next=even->next;
	    odd=even->next;
	    //agar odd null hua toh
	    if(odd->next==NULL)
	    {
	        even->next=NULL;
	        odd->next=evenFirst;
	        break;
	    }
	    //nhi toh ab even ko badhayenge
	    even->next=odd->next;
	    even=odd->next;
	}
}
