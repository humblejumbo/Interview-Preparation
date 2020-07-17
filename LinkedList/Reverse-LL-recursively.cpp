// https://classroom.codingninjas.com/app/classroom/me/1664/content/35832/offering/393206/problem/14


node *reverse_linked_list_rec(node *head)
{    
    if(head==NULL || head->next==NULL)
        return head;
    
    node* revhead=reverse_linked_list_rec(head->next);
    head->next->next=head;
    head->next=NULL;
    return revhead;
}
