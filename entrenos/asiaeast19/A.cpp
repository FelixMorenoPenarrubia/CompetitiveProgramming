#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for(ll v=0; 2*v < n+1; ++v) {
        for(ll h=0; 2*h < (m+1); ++h) {
            if(v==0 and h==0) continue;
            ans += (n+1-2*v)*(m+1-2*h);
            if(v!=0 and h!=0)  ans += (n+1-2*v)*(m+1-2*h);
        }
    }
    cout << ans << endl;
}
