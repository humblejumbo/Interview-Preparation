//https://classroom.codingninjas.com/app/classroom/me/1664/content/38708/offering/429688/problem/5733


Node* reverse(Node* head)
{
    if(head==NULL || head->next==NULL)
        return head;    
    
    Node* revhead=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return revhead;
}

Node* sortedMerge(Node* h1, Node* h2)
{
    Node* result=NULL;
    
    if(h1==NULL)
        return h2;
    
    if(h2==NULL)
        return h1;
    
    if(h1->data<=h2->data)
    {
        result=h1;
        result->next=sortedMerge(h1->next,h2);
    }
    else
    {
        result=h2;
        result->next=sortedMerge(h1,h2->next);
    }
    
    return result;
}
Node* sorting(Node *head)
{
	//Write your code here.
    
    if(head==NULL)      //Empty List
        return head;
    
    Node* ptr=head;
    
    while(ptr->next!=NULL && ptr->data<=ptr->next->data)
        ptr=ptr->next;
    
    if(ptr->next==NULL)     //Strictly Increasing
        return head;
    
    else if(ptr==head)		//Strictly Decreasing
    {
        Node* revhead=reverse(head);  
        return revhead;
    }
    
    else			// Strictly Increasing then decreasing
    {
        Node* point=ptr->next;
        ptr->next=NULL;
        Node* h1=head;
        Node* h2=reverse(point);
        head=sortedMerge(h1,h2);
        return head;
    }  
    
}
