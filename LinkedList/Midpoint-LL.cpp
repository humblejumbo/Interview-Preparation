//https://classroom.codingninjas.com/app/classroom/me/1664/content/35832/offering/393211/problem/328

node* midpoint_linkedlist(node *head)
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
