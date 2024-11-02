// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// const int INF = 1e9; // Represents infinity

// void shortestPathAlgorithm(vector<vector<int>>& W) {
//     int M = W.size();
//     vector<vector<int>> Q = W;

//     // Initialize the Q matrix
//     for (int i = 0; i < M; i++) {
//         for (int j = 0; j < M; j++) {
//             if (i != j && Q[i][j] == 0) {
//                 Q[i][j] = INF;
//             }
//         }
//     }

//     // Update Q matrix
//     for (int k = 0; k < M; k++) {
//         for (int i = 0; i < M; i++) {
//             for (int j = 0; j < M; j++) {
//                 Q[i][j] = min(Q[i][j], Q[i][k] + Q[k][j]);
//             }
//         }
//     }

//     // Print the result
//     cout << "The shortest path matrix is: " << endl;
//     for (int i = 0; i < M; i++) {
//         for (int j = 0; j < M; j++) {
//             if (Q[i][j] == INF) {
//                 cout << "INF ";
//             } else {
//                 cout << Q[i][j] << " ";
//             }
//         }
//         cout << endl;
//     }
// }

// int main() {
//     // Sample input: weighted graph with 4 nodes
//     vector<vector<int>> W = {
//         {0, 3, INF, 7},
//         {8, 0, 2, INF},
//         {5, INF, 0, 1},
//         {2, INF, INF, 0}
//     };

//     shortestPathAlgorithm(W);

//     return 0;
// }

// /*
// 0 3 INF 7
// 8 0 2 INF
// 5 INF 0 1
// 2 INF INF 0

// */

// /*
// 0 3 5 6
// 7 0 2 3
// 3 6 0 1
// 2 5 7 0
  
// */


#include<bits/stdc++.h>
using namespace std;

long long mat[100][100];

void warshal(int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
}

void print(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
   
    int n;// number of nodes
    cin >> n;
    memset(mat,0,sizeof(mat));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> mat[i][j];
            
        }
    }
    cout << "Initial state " << endl;
    print(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==0) mat[i][j]=INT_MAX;
        }
    }
    warshal(n);
    cout << "Final state " << endl;
    print(n);
}

// Initial state 
// 7 5 0 0 
// 7 0 0 2 
// 0 3 0 0 
// 4 0 1 0 
// Final state 
// 7 5 8 7 
// 6 6 3 2 
// 9 3 6 5 
// 4 4 1 6 