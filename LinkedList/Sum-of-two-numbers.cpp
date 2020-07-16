// https://classroom.codingninjas.com/app/classroom/me/1664/content/38708/offering/429683/problem/5732


#include<bits/stdc++.h>
using namespace std;

int getSize(Node* ptr)
{
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    
    return count;
}

Node* addSameSize(Node* head1,Node* head2,int *carry)
{
    if(head1==NULL)
        return NULL;
    
    Node* res=new Node(0);
    
    res->next=addSameSize(head1->next,head2->next,carry);
    int sum=head1->data+head2->data+ *carry;
    res->data=sum%10;
    *carry=sum/10;
    
    return res;    
}

Node* addRemainingLL(Node* head1,Node* curr, int* carry)
{
    if(head1==curr)
        return NULL;
    
    Node* ans=addRemainingLL(head1->next,curr,carry);
    Node* res=new Node(0);
    res->next=ans;
    int sum=head1->data+ *carry;
    res->data=sum%10;
    *carry=sum/10;
    
    return res;    
        
}

void addnumbers(Node* head1, Node* head2, Node** result)  
{  
    //Write your code here.
    
    if(head1==NULL)
    {
        *result=head2;
        return;
    }
    
    if(head2==NULL)
    {
        *result=head1;
        return;
    }
    
    int size1=getSize(head1);
    int size2=getSize(head2);
    int carry=0;
    
    if(size1==size2)
    {        
        *result=addSameSize(head1,head2,&carry);
    }
    else
    {
        int diff=abs(size1-size2);
        if(size2>size1)
            swap(head1,head2);
        
        Node* curr=head1;        
        while(diff--)
            curr=curr->next;
        
        *result=addSameSize(curr,head2,&carry);
        Node* temp=addRemainingLL(head1,curr,&carry);
        
		Node* ptr=temp;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        
        ptr->next=*result;
        *result=temp;
    } 
    
     if(carry==1)
    {
        Node* temp=new Node(1);
        temp->next=*result;
        *result=temp;
    }
    
}
