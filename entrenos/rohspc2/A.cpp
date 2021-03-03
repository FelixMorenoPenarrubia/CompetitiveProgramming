#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    int n;
    cin >> n;
    vi a(n);
    for(auto &x : a) cin >> x;
    ll ans = 0;
    ll mn = 1e9;
    for(auto x : a) {
        ans += x - (1-x%2);
        mn = min(mn, x-(1-x%2));
    }
    if(n%2) cout << ans << endl;
    else cout << ans-mn << endl;
}
