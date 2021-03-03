#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

ll solve2(ll t, ll na, ll a, ll nb, ll b, ll k) {
    ll ans = 0;
    if(na + nb < k or t==0) return 0;
    if(a > b) return solve2(t, nb, b, na, a, k);
    if(na == 0) return solve2(t, nb, b, na, b, k);
    if(a == b) {
        return min((a*(na+nb))/k, t);
    }
    ans = min(a, t);
    ans += solve2(t-ans, na-(k-nb), a, nb, b-a, k);
    return ans;
    
}

ll solve(ll t, ll n, ll a, ll b, ll k) {
    ll ans = 0;
    //cerr << t << " " << n << " " << a << " " << b << " " << k << endl;
    if(2*k <= n) {
        ll times = n/(2*k);
        ans = min(t, times*(a+b));
        ans = ans + solve(t-ans, n%(2*k), a, b, k); 
    }
    else {
        if(n < k) {
            ans = 0;
        }
        else {
            ans = solve2(t, (n+1)/2, a, n/2, b, k);
        }
    }
    return min(ans, t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t, n, a, b, k;
    cin >> t >> n >> a >> b >> k;
    cout << solve2(t, (n+1)/2, a, n/2, b, k) << endl;
}
