#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "123456789";
    string str2 = str.substr(3,5);//45678
    size_t pos = str.find("67");
    string str3 = str.substr(pos);//6789
    cout << str2 << endl;
    cout << str3 << endl;
    return 0;
}