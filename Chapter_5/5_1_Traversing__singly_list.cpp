#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
 
void insert_at_tail(Node *&head,Node *&tail,int v)
 {
    Node *newNode = new Node(v);
    if(head == NULL) 
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;

 }

  void Traversing(Node* &head)
 {
    cout<<endl;
    cout<<"Your Linked List: ";
    Node *tmp=head;
    while(tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
    cout<<endl<<endl;
 }
int main()
{
   int val;
   Node* head =NULL;
   Node* tail =NULL;
   cout<<"Take input : "<<endl;
   while(true)
   {
    cin>>val;
    if(val==-1) break;
    insert_at_tail(head,tail,val);
   }  
   Traversing(head);
   return 0;
}