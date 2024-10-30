#include<bits/stdc++.h>
using namespace std;
const int N =  1e5;
vector<pair<int,int>> v[N];
long long dis[N];

class cmp
{
    public:
           bool operator()(pair<int,int> a,pair<int,int> b)
           {
             return a.second > b.second;
           }
};
void dijkstr(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({src,0});
    dis[src]=0;
    while(!pq.empty())
    {
        pair<int,int> p = pq.top();
       int pnode = p.first;
       int pcost = p.second;
       pq.pop();
        for(auto child:v[pnode])
        {
            int cnode = child.first;
            int ccost = child.second;
            if(dis[cnode]>(dis[pnode]+ccost))
            {
                dis[cnode]=dis[pnode]+ccost;
                pq.push({cnode,dis[cnode]});
            }
            dis[cnode] = min(dis[cnode],dis[pnode]+ccost);
        }
    }
}
int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
       // v[b].push_back({b,c});
    }
    for(int i=0;i<n;i++)
    {
        dis[i]=INT_MAX;
    }
    int src;
    cin >> src;
    dijkstr(src);

    for(int i=0;i<n;i++) 
    {
        cout << i << "->" << dis[i] << endl;
    }

}
