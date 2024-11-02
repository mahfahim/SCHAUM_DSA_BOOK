#include<bits/stdc++.h>
using namespace std;


vector<int> buildPatternMatchingTable(const string& pattern)
{
    int lp = p.length();
    vector<int> F(m+1,0);
    int k = 0

    for(int i)
}

void findPattern2(const string &text,const string &pattern)
{
    int lt = text.length();
    int lp = text.length();

    if(lp == 0) return 0 ;

    vector<int> F = buildPatternMatchingTable(pattern)
}
int main()
{
    string text,pattern;
    cin >> text >> pattern;

    int index = findPattern2(text,pattern);
    if(index != -1)
        cout << "Patern found at index "<< index << endl;
    else 
        cout << "Not found" << endl;

    return 0;
    
}