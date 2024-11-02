#include<bits/stdc++.h>
using namespace std;

int main() {

    string s = "0123456789";
    cout << "Before : ";
    cout << s << endl;
    s.replace(3,2,"Fahim");
    // index = 3 te , 2 ghor delete kore "Fahim" insert korbe
    cout << "After  : ";
    cout << s << endl;

    return 0;
}