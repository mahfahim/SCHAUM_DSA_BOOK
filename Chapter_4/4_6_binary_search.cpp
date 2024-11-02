#include<bits/stdc++.h>
using namespace std;

bool binary_search(int a[],int item,int n)
{
      int mid;
      int l=0,r=n-1;
      while(l<=r)
      {
        mid = (l+r)/2;
        if(a[mid]==item) 
        {
            return true;
        }
        else if(a[mid]<item)
        {
             l=mid+1;
        }
        else if(a[mid]>item)
        {
             r=mid-1;
        }
      }
      return false;
    
}
int main()
{
    int n;
    cin >> n; 
    int a[n+5];
    for(int i=0;i<n;i++) cin >> a[i];
    
    int item ;
    cin >> item;
    sort(a,a+n);

    bool flag = binary_search(a,item,n);

    if(flag) cout << "Found" << endl;
    else cout << "Not Found" << endl;
}