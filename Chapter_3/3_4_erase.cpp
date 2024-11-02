#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "0123456789";
    cout << "Before Erase : ";
    cout << s << endl;
    s.erase(3,2);
    cout << "After Erase  : ";
    cout << s << endl;
}