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
