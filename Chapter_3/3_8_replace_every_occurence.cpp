#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Bangla amr Bangla amr matrivasha";
    string p = "amr";
    string q = "tomar";
    int k = s.find(p);
    while(k != string::npos)
    {
        s.replace(k,p.size(),q);
        k = s.find(p);
    }
    cout << s << endl;
}