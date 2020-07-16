//https://classroom.codingninjas.com/app/classroom/me/1664/content/38708/offering/429687/problem/5761

Node* flattenlist(Node* node) 
{ 
    //Write your code here
    
    if(node==NULL)					//Very similar to BST to LL in BST-1.
        return NULL;
    
    //Node* next=node->next;		//remembering the next node
    Node* l=flattenlist(node->down);	
    Node* r=flattenlist(node->next);
    
    node->next=l;
    
    Node* tail=node;    
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    
    tail->next=r;    
    return node;
} 
