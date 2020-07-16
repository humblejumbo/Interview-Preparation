//https://classroom.codingninjas.com/app/classroom/me/1664/content/38708/offering/429685/problem/5756

#include<bits/stdc++.h>
using namespace std;
Node* flattenlistcorrect(Node *hp)
{
	//Write your code here.
    if(hp==NULL)
        return NULL;
    
    Node* finalhead=hp;
    Node* finaltail=hp;
    Node* currptr=hp;
    
    while(currptr!=NULL)
    {
        Node* ptr=finaltail;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            finaltail->next=ptr;
            finaltail=finaltail->next;
        }
        
        if(currptr->down!=NULL)
        {
            finaltail->next=currptr->down;
            finaltail=finaltail->next;
            currptr->down=NULL;
        }
        
        currptr=currptr->next;
    }  
    
    return finalhead;  
    
}
