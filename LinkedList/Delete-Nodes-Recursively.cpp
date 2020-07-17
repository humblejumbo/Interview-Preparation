//https://classroom.codingninjas.com/app/classroom/me/1664/content/35832/offering/393204/problem/325

Node* deleteNodeRec(Node *head, int i) {
    
    if(head==NULL)
        return head;
    
    if(i==0)
    {
        head=head->next;
        return head;
    }
    
    head->next=deleteNodeRec(head->next,i-1);
    return head;
    
}
