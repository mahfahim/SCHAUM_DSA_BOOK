// #include<bits/stdc++.h>
// using namespace std;

// class Edge
// {
//     public: 
//            int a,b,c;
//            Edge(int x,int y,int z)
//            {
//              a=x;
//              b=y;
//              c=z;
//            }
// };

// const int N  = 1e5;
// long long dis[N];

// int main()
// {
//     int n,e;
//     cin >> n >> e;
//     vector<Edge> list ;
//     while(e--)
//     {
//         int a,b,c;
//         cin >> a >> b >> c;
//         list.push_back(Edge(a,b,c));
//     }
    
//     for(int i=0;i<n;i++)
//     {
//         dis[i]=INT_MAX;
//     }
//     dis[0]=0;
//     for(int i=1;i<=n-1;i++)
//     {
//         for(Edge eg:list)
//         {
//             int u = eg.a;
//             int v = eg.b;
//             int w = eg.c;

//             if(dis[u]<INT_MAX && dis[u]+w < dis[v])
//             {
//                 dis[v]=dis[u]+w;
//             }
//         }
//     }
//     for(int i=0;i<n;i++) 
//     {
//         cout << i << " -> " << dis[i] << endl;
//     }
// }


#include<bits/stdc++.h>
using namespace std;

class Edge
{
    public: 
           int a,b,c;
           Edge(int x,int y,int z)
           {
             a=x;
             b=y;
             c=z;
           }
};

const int N  = 1e5;
long long dis[N];

int main()
{
    int n,e;
    cin >> n >> e;
    vector<Edge> list ;
    while(e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        list.push_back(Edge(a,b,c));
    }
    
    for(int i=0;i<n;i++)
    {
        dis[i]=INT_MAX;
    }
    dis[0]=0;
    for(int i=1;i<=n-1;i++)
    {
        for(Edge eg:list)
        {
            int u = eg.a;
            int v = eg.b;
            int w = eg.c;

            if(dis[u]<INT_MAX && dis[u]+w < dis[v])
            {
                dis[v]=dis[u]+w;
            }
        }
    }
    bool flag = true;
           for(Edge eg:list)
        {
            int u = eg.a;
            int v = eg.b;
            int w = eg.c;

            if(dis[u]<INT_MAX && dis[u]+w < dis[v])
            {
                flag = false;
            }
        }

        if(flag) cout << "NOT cycle" << endl;
        else cout << "Cycle detected " << endl;
}


