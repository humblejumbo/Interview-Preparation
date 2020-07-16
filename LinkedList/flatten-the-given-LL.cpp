// https://classroom.codingninjas.com/app/classroom/me/1664/content/38708/offering/429684/problem/5749

Node* sortedMerge(Node* a, Node* b)
{
    Node* result=NULL;
    
    if(a==NULL)
        return b;
    
    if(b==NULL)
        return a;
    
    if(a->data<=b->data)
    {
        result=a;
        result->down=sortedMerge(a->down,b);
    }
    else
    {
        result=b;
        result->down=sortedMerge(a,b->down);
    }
    
    return result;
        
}

Node* flat(Node* head)
{
	// Write your code here. You just need to return the head of flattened linked list.
    if(head==NULL || head->right==NULL)
        return head;
    
    Node* temp=flat(head->right);
    head->right=NULL;
    Node* finalHead=sortedMerge(head,temp);
    return finalHead;    
}
