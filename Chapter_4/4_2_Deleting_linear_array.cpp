#include<bits/stdc++.h>
using namespace std;

int arr[100];
void delete_val(int arr[],int len,int pos)
{
   for(int i=pos;i<len;i++)
   {
      arr[i-1]=arr[i];
   }
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];

    int ins_pos;
    cin >> ins_pos;// 1 based index
    
    cout << "Before insertion : ";
    for(int i=0;i<n;i++) cout << arr[i] <<" ";

    delete_val(arr,n,ins_pos);

    cout << "\nAfter insertion  : ";
    for(int i=0;i<n-1;i++) cout << arr[i] <<" ";

}