#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n+5];
    for(int i=0;i<n;i++) cin >> a[i];

    int item ;
    cin >> item;
    bool flag = true;
    int pos ;
    for(int i=0;i<n;i++)
    {
        if(a[i]==item) 
        {
            flag = false;
            pos = i;
            break;
        }
    }
    if(flag) cout << "Not found" << endl;
    else cout << "Item is found at position " << pos+1 <<endl;

}