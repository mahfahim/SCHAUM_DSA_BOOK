#include<bits/stdc++.h>
using namespace std;

int main() {

    string s = "0123456789";
    cout << "Before : ";
    cout << s << endl;
    s.insert(3,"Fahim");
    // index = 3 te "Fahim" insert korbe
    cout << "After  : ";
    cout << s << endl;

    return 0;
}