//https://classroom.codingninjas.com/app/classroom/me/1664/content/38708/offering/429682/problem/773


int length(Node<int>* head)
{
    Node<int>* ptr=head;
    int len=0;
    
    while(ptr!=NULL)
    {
        len++;
        ptr=ptr->next;
    }
    
    return len;
}

int getIntesectionNode( Node<int>* head1,  Node<int>* head2)
{
	int len1=length(head1);
	int len2=length(head2);
    
    Node<int>* tail1=head1;
    Node<int>* tail2=head2;
    
    while(len1>len2)
    {
        tail1=tail1->next;
        len1--;
    }    
    while(len2>len1)
    {
        tail2=tail2->next;
        len2--;
    }
    
    while(tail1!=NULL && tail2!=NULL && tail1->data!=tail2->data)
    {
        tail1=tail1->next;
        tail2=tail2->next;
    }
    
    if(tail1!=NULL)
        return tail1->data;
    else
        return -1;
    
}
 
