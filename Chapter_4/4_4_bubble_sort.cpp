#include<bits/stdc++.h>
using namespace std;

void bubblesort(int arr[],int n)
{
   for(int i=n-1;i>=1;i--)
   {
     for(int j=1;j<=i;j++)
     {
        if(arr[j] < arr[j-1]) swap(arr[j],arr[j-1]);
     }
   }
}

int main()
{
    int n;
    cin >> n;
    int arr[n+5];
    for(int i=0;i<n;i++) 
    {
        cin >> arr[i];
    }
    cout << "Befor sort : ";
    for(int i=0;i<n;i++) cout<< arr[i] << " ";
    cout << endl;
    bubblesort(arr,n);
    cout << "After sort : ";
    for(int i=0;i<n;i++) cout << arr[i] <<" ";
    cout << endl;

}