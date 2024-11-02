#include<bits/stdc++.h>
using namespace std;

int findPattern(const string &text,const string &pattern)
{
    int lp =pattern.length();
    int lt =text.length();
    int mx = lt - lp;

    for(int i=0;i<= mx;i++)
    {
        int j;
        for( j=0;j<lp;j++)
        {
            if(pattern[j] != text[i+j])
            {
                break;
            }
        }
        if(lp == j)
        {
            return j;
        }
    }
    return -1;
}
int main()
{
    string text, pattern;

    cin >> text >> pattern;

    int index = findPattern(text,pattern);
    if(index != -1)
       cout << "Pattern found at index: "<< index << endl;
    else 
       cout << "Not found" << endl;

   return 0;
}


// input

// Text: "aababc"
// Pattern: "abc"

// output

// Pattern found at index: 