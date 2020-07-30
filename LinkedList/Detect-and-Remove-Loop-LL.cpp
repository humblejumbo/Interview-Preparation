// { Driver Code Starts
// driver code
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

#include<bits/stdc++.h>

// void removeLoop(Node* head)          // Using O(n) space and O(n)Time
// {
//     // code here
//     // just remove the loop without losing any nodes
    
//     unordered_set<Node*> st;
//     Node* prev=NULL;
//     Node* ptr=head;
    
//     while(ptr!=NULL && st.find(ptr)==st.end())
//     {
//         st.insert(ptr);
//         prev=ptr;
//         ptr=ptr->next;
//     }
    
//     prev->next=NULL;
// }


//Floyd Cycle Detection Algorithm
void removeLoopHelper(Node* loopNode, Node* head)
{
    Node* ptr2=loopNode;
    Node* ptr1=head;
    
    while(1)
    {
        ptr2=loopNode;
        while(ptr2->next!=loopNode && ptr2->next!=ptr1)
            ptr2=ptr2->next;
            
        if(ptr2->next==ptr1)
            break;
        
        else
            ptr1=ptr1->next;
    }
    
    ptr2->next=NULL;
}

void removeLoopHelper2(Node* loopNode, Node* head)
{
    Node* ptr1=loopNode;
    Node* ptr2=loopNode;
    
    int k=1;
    while(ptr1->next!=ptr2)
    {
        ptr1=ptr1->next;
        k++;
    }
        
    ptr1=head;
    ptr2=head;
    
    while(k--)
    {
        ptr2=ptr2->next;
    }
    
    while(ptr1->next!=ptr2->next)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    
    while (ptr2->next != ptr1) 
        ptr2 = ptr2->next; 
  
    ptr2->next=NULL;
}

void removeLoop(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast)
        {
            removeLoopHelper2(slow,head);
            break;
        }
    }
}
