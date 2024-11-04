#include<bits/stdc++.h>
using namespace std;


void mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
         cout << arr[i] << " ";
     cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr[n+5];
    for(int i=0;i<n;i++) cin >> arr[i];
    mergeSort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}