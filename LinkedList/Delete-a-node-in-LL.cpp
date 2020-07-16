//https://classroom.codingninjas.com/app/classroom/me/1664/content/38708/offering/429681/problem/5748

void deletenode(Node* temp) {
    //Write your code here
    
    Node* ptr=temp->next;
    temp->data=temp->next->data;
    temp->next=temp->next->next;
    delete(ptr);
}
