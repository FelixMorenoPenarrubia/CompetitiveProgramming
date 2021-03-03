#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll n_or = n;
    if(n == 1) {
        cout << "No" << endl;
        return 0;
    }
    int pc = 0;
    while(n > 0) {
        if(n&1) pc++;
        n >>= 1;
    }
    if(pc > 2) {
        cout << "No" << endl;
    }
    else if(pc == 2) {
        cout << ((n_or&1) ? "Yes" : "No") << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}
