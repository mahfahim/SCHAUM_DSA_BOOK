
#include<bits/stdc++.h>
using namespace std;

int mat[100][100];

void warshal(int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               mat[i][j] = mat[i][j] | (mat[i][k] & mat[k][j]);
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
    cout << "Final state " << endl;
    warshal(n);
    print(n);
}
