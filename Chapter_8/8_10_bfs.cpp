// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// // Constants representing statuses
// const int READY = 1;
// const int WAITING = 2;
// const int PROCESSED = 3;

// void bfs(vector<vector<int>>& graph, int startNode) {
//     int numNodes = graph.size();
//     vector<int> status(numNodes, READY); // Initialize all nodes to the READY state
//     queue<int> q;

//     // Put the starting node in the queue and change its status to WAITING
//     q.push(startNode);
//     status[startNode] = WAITING;

//     while (!q.empty()) {
//         // Remove the front node of the queue and process it
//         int node = q.front();
//         q.pop();
//         cout << "Processing node: " << node << endl;
//         status[node] = PROCESSED;

//         // Add all neighbors of the node that are in the READY state to the queue
//         for (int neighbor : graph[node]) {
//             if (status[neighbor] == READY) {
//                 q.push(neighbor);
//                 status[neighbor] = WAITING;
//             }
//         }
//     }
// }

// int main() {
//     // Sample graph represented as an adjacency list
//     vector<vector<int>> graph = {
//         {1, 2},    // Neighbors of node 0
//         {0, 3, 4}, // Neighbors of node 1
//         {0, 4},    // Neighbors of node 2
//         {1, 5},    // Neighbors of node 3
//         {1, 2, 5}, // Neighbors of node 4
//         {3, 4}     // Neighbors of node 5
//     };

//     int startNode = 0; // Start BFS from node 0
//     bfs(graph, startNode);

//     return 0;
// }
// /*
// Processing node: 0
// Processing node: 1
// Processing node: 2
// Processing node: 3
// Processing node: 4
// Processing node: 5

// */

#include<bits/stdc++.h>
using namespace std;

// const int NN = 1e5;
map<char,vector<char>> v;
map<char,bool> vis;
map<char,char> par;

void bfs(char src)
{
   queue<char> q;
   q.push(src);
   char papa = q.front();
   vis[papa]=false;
   par[src]=NULL;  
   while(!q.empty())
   {
       papa = q.front();
       q.pop();
        for(char child:v[papa])
        {
            if(vis[child]==false)
            {
                q.push(child);
                vis[child]=true;
                par[child]=papa;
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
    // memset(vis,false,sizeof(vis));
    // memset(par,-1,sizeof(par));
    char src,des;
    cin>> src >> des;
    bfs(src);
    vector<char> path;
    path.push_back(des);
    char temp = des;
    while(temp != NULL)
    {
        temp = par[temp];
        path.push_back(temp);
    }
    reverse(path.begin(),path.end());
    for(char u:path)
    {
        if(u==NULL) continue;
        if(u==des) cout << u;
        else cout << u <<" -> ";
    }
    cout << endl;
    
}