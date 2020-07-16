// https://classroom.codingninjas.com/app/classroom/me/1664/content/38708/offering/429686/problem/5754


Node* cloningLL(Node* head)
{
    if(head==NULL)
        return NULL;
    
    Node* nodenext=head->next;
    head->next=new Node(head->data);
    head->next->next=nodenext;
    
    if(nodenext!=NULL)
        nodenext->next=cloningLL(nodenext);
    
    return head->next;
}


void setRandoms(Node* temp,Node* cloneNode)
{
    if(temp==NULL || cloneNode==NULL)
        return;
    
    if(temp->arbitrary!=NULL)
        cloneNode->arbitrary=temp->arbitrary->next;
    else
        cloneNode->arbitrary=NULL;
    
    if(temp->next!=NULL && cloneNode->next!=NULL)
        setRandoms(temp->next->next,cloneNode->next->next);
}


void seperation(Node* temp, Node* cloneNode)
{
    if(temp==NULL || cloneNode==NULL)
        return;
    
    if(cloneNode->next!=NULL)
    {
        Node* cloneNodeNext=cloneNode->next->next;;
        temp->next=temp->next->next;
        cloneNode->next=cloneNodeNext;
    }
    else
        temp->next=NULL;
    
    seperation(temp->next,cloneNode->next);
}
Node* clone(Node* head)
{
   //Write your code here
    
    Node* clonedHead=cloningLL(head);
    setRandoms(head,clonedHead);
    seperation(head,clonedHead);
    return clonedHead;
}
