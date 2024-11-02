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

  Node* Search(Node* &head,int item)
 {
    cout<<endl;
    cout<<"Your Item location : ";
    Node *tmp=head;

    while(tmp != NULL)
    {
        if(tmp->val == item) 
        {
           return tmp;
        }
        tmp=tmp->next;
    }
     return NULL;
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
   int item;
   cin >> item;
   auto ans = Search(head,item);
   
   if(ans == NULL) cout << "Item Not found" << endl;
   else cout << ans << endl;
   
   return 0;
}