#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Input first matrix  : " << endl;
    int x,y;
    cin >> x >> y;
    int mA[x+5][y+5];
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            cin >> mA[i][j];
        }
    }

    cout << "Input second matrix  : " << endl;
    int p,q;
    cin >> p >> q;
    int mB[p+5][q+5];
    for(int i=1;i<=p;i++)
    {
        for(int j=1;j<=q;j++)
        {
            cin >> mB[i][j];
        }
    }
    if(y!=p) 
    {
        cout << "Not possible Multiplication" <<endl;
        return 0 ;
    }
    int mul[x+5][q+5];
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=q;j++)
        {
          for(int k=1;k<=p;k++)
          {
             mul[i][j] = mA[i][k] * mB[k][j];
          }
        }
    }
    
    cout << "Multiplication Matrix :" << endl;
     for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=q;j++)
        {
           printf("%2d ",mul[i][j]);
        }
        cout << endl;
    }

}