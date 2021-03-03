#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t=0; t < T; ++t) {
        ll l, r;
        cin >> l >> r;
        bool s = false;
        if(l < r) {
            swap(l, r);
            s = true;
        }
        
        ll u = 2e9;
        ll d = 0;
        while(u-d > 0) {
            ll m = (d+u)/2;
            ll tri = (m*(m+1))/2;
            if(l-tri <= r) {
                u = m;
            }
            else {
                d = m+1;
            }
        }
        ll b1 = d;
        l -= (b1*(b1+1))/2;
        if(l < r) {
            swap(l, r);
            s = !s;
        }
        ll b2;
        
        if(l < b1+1) {
            b2 = b1;
        }
        else {
            if(b1%2) {
                l -= b1+1;
                b1++;
                swap(l, r);
                s = !s;
            }
            
            ll u = 2e9;
            ll d = 0;
            while(u-d > 0) {
                ll m = 2*((d+u)/2)+1+b1;
                ll tri = m*m-(b1*(b1+1))/2;
                if(l-tri < m+2) {
                    u = m;
                }
                else {
                    d = m+1;
                }
            }
            ll b2 = 2*d+1+b1;
            
            l -= d*d-(b1*(b1+1))/2;
            
        }
        
        
        
        if(s) swap(l, r);
        
        
    }
    
}
