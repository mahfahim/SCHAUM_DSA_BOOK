// // MH_Nazmul
// // Let it be as simple

// #include <bits/stdc++.h>
// using namespace std;
// #define push_back push_back
// #define nl cout << "\n"
// #define all(x) x.begin(), x.end()
// #define allr(x) x.rbegin(), x.rend()
// #define f(a, b, c) for (int a = b; a < c; a++)
// #define cin(vec, n) \
//     f(i, 0, n) { cin >> vec[i]; }
// #define int long long
// const int N = 2e5 + 10;
// const int M = 1e9 + 7;

// void prims_cal(vector<vector<pair<int, int>>> &graph)
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     vector<bool> vis(N, false);
//     pair<int, int> zero = {0, 1};
//     pq.push(zero);
//     int node, weight, total_cost = 0;
//     while (!pq.empty())
//     {
//         node = pq.top().second;
//         weight = pq.top().first;
//         pq.pop();
//         if (vis[node] == true)
//             continue;

//         vis[node] = true;
//         total_cost += weight;

//         for (auto it : graph[node])
//         {
//             if (vis[it.second])
//                 continue;
//             pq.push({it.second, it.first});
//         }
//     }
//     cout << total_cost;
// }
// int main();
// {
//     int node, edge;
//     cin >> node >> edge;
//     vector<vector<pair<int, int>>> graph(node + 5);
//     while (edge--)
//     {
//         int v1, v2, w;
//         cin >> v1 >> v2 >> w;
//         graph[v1].push_back({v2, w});
//         graph[v2].push_back({v1, w});
//     }
//     prims_cal(graph);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<pair<int,int>> mat[N];
bool vis[N];

class cmp
{
    public:
           bool operator()(pair<int,int> a,pair<int,int> b)
           {
               return a.second > b.second;
           }
};
int  prims(int src)
{
   priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
   pq.push({src,0});
   int totalcost = 0;
   while(!pq.empty())
   {
       pair<int,int> papa = pq.top();
       int pnode = papa.first;
       int pcost = papa.second;
       if(vis[pnode]==false) totalcost += pcost;
       pq.pop();
       vis[pnode]=true;
       for(pair<int,int> child:mat[pnode])
       {
           int cnode = child.first;
           int ccost = child.second;
           if(vis[cnode]==false)
           {
             pq.push({cnode,ccost});
           }
       }
       
   }
   return totalcost;
}

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        mat[a].push_back({b,c});
        mat[b].push_back({a,c});
    }
    memset(vis,false,sizeof(vis));
    int totalcost = prims(1);
    cout << totalcost << endl;

}