#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "0123456789";
    string str2 ="67";
    size_t found2 = str.find(str2);
    if(found2 !=string::npos ) 
     cout <<"Str2 found at position "<<found2 << endl;
    else
     cout <<"Str2 not found" <<endl;

    string str3 ="100";
    size_t found3 = str.find(str3);
    if(found3 !=string::npos ) 
     cout <<"Str3 found at position "<<found3 << endl;
    else
     cout <<"Str3 not found" <<endl;
    
    
}

