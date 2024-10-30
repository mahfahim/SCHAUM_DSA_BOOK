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
