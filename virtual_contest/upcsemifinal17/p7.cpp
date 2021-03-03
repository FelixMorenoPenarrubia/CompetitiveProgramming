#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


vector<ll> fib;

ll f(ll n, ll m) {
    if(m == 0) return 0;
    int l = 0;
    int r = 90;
    while(r > l+1) {
        int d = (l+r)/2;
        if(fib[d] > n) {
            r = d;
        }
        else {
            l = d;
        }
    }
    return fib[l]+f(n-fib[l], m-1);
}


int main() {
    fib.push_back(0);
    fib.push_back(1);
    for(int i=0; i < 88; ++i) {
        fib.push_back(fib[i]+fib[i+1]);
    }
    ll n;
    ll m;
    while(cin >> n>> m) cout << n-f(n, m) << endl;
}
