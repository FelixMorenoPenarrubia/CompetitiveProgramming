#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


ll absol(ll x) {
    return (x > 0) ? x : -x;
}

void caso(ll n, ll p) {
    ll pc = 0;
    ll lc = 0;
    vector<ll> l (n);
    ll lsum = 0;
    for(int i=0; i < n; ++i) cin >> l[i];
    for(int i=0; i < n; ++i) lsum += l[i];
    ll eq = lsum/n;
    ll clsum = l[0]-eq;
    if(clsum > 0) {
        pc += p;
        lc += l[0]-eq;
    }
    for(int i=1; i < n; ++i) {
        ll pclsum = clsum;
        clsum += l[i]-eq;
        if(pclsum < 0) {
            pc += p;
            lc -= pclsum;
        }
        if(clsum > 0) {
            pc += p;
            lc += clsum;
        }
        //cerr << i << " clsum = " << clsum << " pclsum = " << pclsum << endl << "pc = " << pc << " lc = " << lc << endl;
      
    }
    cout << pc + lc << endl;
    
}


int main() {
    ll n;
    ll p;
    while(cin >> n>> p) caso(n, p);
}
