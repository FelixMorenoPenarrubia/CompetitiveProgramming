#include<bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
    int a;
    cin >> a;
    string r;
    cin >> r;
    if(r == "G") {
        cout << "OK" << endl;
    }
    else if(r == "PG") {
        if(a < 13) {
            cout << "OK IF ACCOMPANIED" << endl;
        }
        else {
            cout << "OK" << endl;
        }
    }
    else if(r == "R-13") {
        if(a < 13) {
            cout << "ACCESS DENIED" << endl;
        }
        else {
           cout << "OK" << endl; 
        }
    }
    else if(r == "R-16") {
        if(a < 16) {
            cout << "ACCESS DENIED" << endl;
        }
        else {
           cout << "OK" << endl; 
        }
    }
    else if(r == "R-18") {
        if(a < 18) {
            cout << "ACCESS DENIED" << endl;
        }
        else {
           cout << "OK" << endl; 
        }
    }
}
