// #include <iostream>
// #include <stack>
// #include <vector>
// using namespace std;

// // Constants for node statuses
// const int READY = 1;
// const int WAITING = 2;
// const int PROCESSED = 3;

// // Function to perform DFS
// void DFS(vector<vector<int>>& graph, int startNode) {
//     int n = graph.size(); // Number of nodes in the graph
//     vector<int> status(n, READY); // Initialize all nodes to READY state
//     stack<int> stk;

//     // Push the starting node onto STACK and change its status to WAITING
//     stk.push(startNode);
//     status[startNode] = WAITING;

//     // Repeat until STACK is empty
//     while (!stk.empty()) {
//         // Pop the top node N of STACK, process it, and change its status to PROCESSED
//         int node = stk.top();
//         stk.pop();
//         cout << "Processing node: " << node << endl;
//         status[node] = PROCESSED;

//         // Push all the neighbors of N that are still in the READY state onto STACK
//         for (int neighbor : graph[node]) {
//             if (status[neighbor] == READY) {
//                 stk.push(neighbor);
//                 status[neighbor] = WAITING;
//             }
//         }
//     }
// }

// int main() {
//     // Sample graph (adjacency list representation)
//     // Node 0 is connected to 1, 2; Node 1 is connected to 0, 3; Node 2 is connected to 0, 4, etc.
//     vector<vector<int>> graph = {
//         {1, 2},  // Neighbors of node 0
//         {0, 3},  // Neighbors of node 1
//         {0, 4},  // Neighbors of node 2
//         {1, 5},  // Neighbors of node 3
//         {2},     // Neighbors of node 4
//         {3}      // Neighbors of node 5
//     };

//     int startNode = 0; // Starting node for DFS

//     // Run the DFS algorithm
//     DFS(graph, startNode);

//     return 0;
// }

// /*
// Processing node: 0
// Processing node: 2
// Processing node: 4
// Processing node: 1
// Processing node: 3
// Processing node: 5

// */


#include<bits/stdc++.h>
using namespace std;

// const int NN = 1e5;
map<char,vector<char>> v;
map<char,bool> vis;
stack<char> ans;

void dfs(char src)
{
   stack<char> st;
   st.push(src);
   char papa = st.top();
   vis[papa]=true;  
   while(!st.empty())
   {
       papa = st.top();
       st.pop();
       cout << papa << endl;
        for(char child:v[papa])
        {
            
            if(vis[child]==false)
            {
                st.push(child);
                vis[child]=true;
            }
        }
   }
 
}

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        char a,b;
        cin >> a >> b;
        v[a].push_back(b);

    }
    char src;
    cin >> src;
    // memset(vis,false,sizeof(vis));
    // memset(par,-1,sizeof(par));
   
    dfs(src);
    
}