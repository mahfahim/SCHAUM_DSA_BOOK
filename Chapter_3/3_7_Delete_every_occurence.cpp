#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Bangla amr Bangla amr matrivasha";
    string p = "amr";
    int k = s.find(p);
    while(k != string::npos)
    {
        s.erase(k,p.length());
        k = s.find(p);
    }
    cout << s << endl;
}