#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void delete_item(Node*& head, Node*& avail, int item) // 5_10
{
    Node* loc = NULL;
    Node* locp = NULL;

 
    find_in_loc(head, item, loc, locp);

   
    if (loc == NULL) {
        cout << "ITEM not in list." << endl;
        return;
    }

    
    if (locp == NULL) { 
        head = head->next;
    } else { 
        locp->next = loc->next;
    }

   
    loc->next = avail;
    avail = loc;
}

void delete_at_loc (Node*& head, Node*& avail, Node* loc, Node* locp) // 5_8
{
    if (loc == NULL) { 
        cout << "Error: Node to delete does not exist." << endl;
        return;
    }

   // locp  means  loc  er ager node;
    if (locp == NULL) { 
        head = head->next;
    } else { 
        locp->next = loc->next;
    }

   
    loc->next = avail;
    avail = loc;
}


void find_in_loc(Node* head, int item, Node*& loc, Node*& locp)// 5_9
{
    if (head == NULL) { 
        loc = NULL;
        locp = NULL;
        return;
    }

    if (head->val == item) { 
        loc = head;
        locp = NULL;
        return;
    }

    Node* save = head;
    Node* ptr = head->next;

    while (ptr != NULL) {
        if (ptr->val == item) { 
            loc = ptr;
            locp = save;
            return;
        }
        save = ptr;
        ptr = ptr->next;
    }

  
    loc = NULL;
    locp = NULL;
}

void find_in_sort(Node* &head, int item, Node*& loc) // 5_6
{
    
    if (head == NULL) {
        loc = NULL;
        return;
    }


    if (item < head->val) {
        loc = NULL;
        return;
    }

    
    Node* save = head;
    Node* tmp = head->next;

    while (tmp != NULL) {
    
        if (item < tmp->val) {
            loc = save;
            return;
        }
    
        save = tmp;
        tmp = tmp->next;
    }

    
    loc = save;

}
void Insert_at_lock(Node*& head, Node*& avail, Node* loc, int item) //5.5
{
    
    if (avail == NULL) {
        cout << "Overflow" << endl;
        return;
    }

    Node* newNode = avail;
    avail = avail->next;

    newNode->val = item;
    newNode->next = NULL;

    if (loc == NULL) { 
       newNode->next = head;
        head = newNode;
    } else { 
        newNode->next = loc->next;
        loc->next = newNode;
    }
}

void Insert_at_head(Node*& head, Node*& avail, int item)//5.4
{
    if (avail == NULL) {
        cout << "OVERFLOW" << endl;
        return;
    }

    Node* newNode = avail;  
    avail = avail->next;     

    newNode->val = item;
    newNode->next = head;   
    head = newNode;         

    cout << "Inserted " << item << " as the first node." << endl;
}

void insert_at_tail(Node*& head, Node*& tail, Node*& avail, int item) 
{
    // Check if there's an available node
    if (avail == NULL) {
        cout << "OVERFLOW" << endl;
        return;
    }

    // Take the first node from avail
    Node* newNode = avail;
    avail = avail->next;

    // Initialize the new node with the given item value
    newNode->val = item;
    newNode->next = NULL;

    // If the list is empty, set head and tail to the new node
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        // Otherwise, link the new node to the end of the list and update the tail
        tail->next = newNode;
        tail = newNode;
    }
}
  Node* SearchSort(Node* &head,int item)//5.3
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
        else if(tmp->val < item)
        {
           tmp=tmp->next;
        }
        else
        {
            return NULL;
        }
        
    }
     return NULL;
 }
  Node* Search(Node* &head,int item)//5.2
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
void printList(Node* head)//5.1
 {
    cout << "Current List : " ;
    Node* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

void initializeAvail(Node*& avail, int numNodes)
{
      for (int i = 0; i < 2*numNodes; ++i) // availnode 2 gun niye rakhchi
    {
        Node* newAvailNode = new Node(0);  // Initialize each node with value 0
        newAvailNode->next = avail; // like stack , avail er upor NewAvailNode
        avail = newAvailNode; // pore NewAvailNode ta avail
    }
}
int main() {
    Node* head = NULL; 
    Node* tail = NULL;
    Node* avail = NULL;
    NOde* loc = NULL;
    int item;
    int numNodes;
    cout << "Enter the number of nodes : ";
    cin >> numNodes;

     initializeAvail(avail,numNodes);

    for (int i = 0; i < numNodes; ++i) {
        cin >> item;
        insert_at_tail(head,tail,avail,item);
    }


    printList(head);
    cin >> item;
    Insert_at_head(head,avail,item);
    printList(head);


    return 0;
}
