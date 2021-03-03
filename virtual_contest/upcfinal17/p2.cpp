#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


ll powr(ll b, int e) {
    if(e==0) return 1;
    ll sq = powr(b, e/2);
    return ((e&1) ? sq*sq*b : sq*sq);
}

int main() {
    ll m;
    set<ll> good;
    for(int i=0; powr(2, i) <= 1e15; ++i) {
        for(int j=0; powr(2, i)*powr(3, j) <= 1e15; ++j) {
            for(int k=0; powr(2, i)*powr(3, j)*powr(5, k) <= 1e15; ++k) {
                good.insert(powr(2, i)*powr(3, j)*powr(5, k));
            }
        }
    }
    while(cin >> m) {
        ll sol = 0;
        ll nm;
        ll p2 = 0;
        ll p3 = 0;
        ll p5 = 0;
        while(m%2 == 0) {
            ++p2;
            m /= 2;
        }
        while(m%3 == 0) {
            ++p3;
            m /= 3;
        }
        while(m%5 == 0) {
            ++p5;
            m /= 5;
        }
        nm = powr(2, p2)*powr(3, p3)*powr(5, p5);
        for(auto it = good.begin(); it != good.end(); ++it) {
            if(*it >= nm) break;
            ++sol;
            if(good.find(nm-*it) == good.end()) ++sol;
        }
        cout << sol << endl;
        
    }
}
