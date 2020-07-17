// https://classroom.codingninjas.com/app/classroom/me/1664/content/35832/offering/393217/problem/17


node* findMid(node *head)
{
    // Write your code here
    
    node* slow=head;
    node* fast=head->next;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    return slow;
}

node* merge(node *head1, node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    
    node* result=NULL;
    
    if(head1==NULL)
        return head2;
    
    if(head2==NULL)
        return head1;
    
    if(head1->data<=head2->data)
    {
       result=head1;
       result->next=merge(head1->next,head2); 
    }
            
    else
    {	
        result=head2;
        result->next=merge(head1,head2->next);
    }        
    
    return result;
}



node* mergeSort(node *head) {
    //write your code here
    
    if(head==NULL || head->next==NULL)
        return head;
    
    node* mid=findMid(head);
    node* half1=head;
    node* half2=mid->next;
    mid->next=NULL;
    
    half1=mergeSort(half1);
    half2=mergeSort(half2);
    
    node* finalHead=merge(half1,half2);
    return finalHead;
}
