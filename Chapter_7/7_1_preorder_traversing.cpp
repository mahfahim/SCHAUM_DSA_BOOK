#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
           int val;
           Node* left;
           Node* right;
           Node(int v)
           {
            val = v;
            left = NULL;
            right = NULL;
           }
};
void preorder(Node* root)
{
    if(root==NULL ) return;
    cout << root->val <<" ";
    preorder(root->left);
    preorder(root->right);
}


int main()
{
   Node* root = new Node(10);
   Node* a = new Node(20);
   Node* b = new Node(30);
   Node* c = new Node(40);
   Node* d = new Node(50);
   Node* e = new Node(60);
   Node* f = new Node(70);
   Node* g = new Node(80);
   Node* h = new Node(90);
   Node* i = new Node(100);

   root->left=a;
   root->right=b;
   a->left=c;
   a->right=h;
   b->right=d;
   c->right=e;
   h->right=i;
   d->left=f;
   d->right=g;

   cout << "PreOrder : ";
   preorder(root);
   cout << endl;
}