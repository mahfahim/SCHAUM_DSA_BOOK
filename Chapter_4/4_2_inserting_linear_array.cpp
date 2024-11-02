#include<bits/stdc++.h>
using namespace std;

int arr[100];
void insert_val(int arr[],int len,int pos,int val)
{
   for(int i=len;i>=pos;i--)
   {
      arr[i]=arr[i-1];
   }
    arr[pos-1]=val;
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];

    int ins_pos ,ins_val;
    cin >> ins_pos >> ins_val;// 1 based index
    
    cout << "Before insertion : ";
    for(int i=0;i<n;i++) cout << arr[i] <<" ";

    insert_val(arr,n,ins_pos,ins_val);

    cout << "\nAfter insertion  : ";
    for(int i=0;i<n+1;i++) cout << arr[i] <<" ";

}