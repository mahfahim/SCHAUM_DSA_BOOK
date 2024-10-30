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
