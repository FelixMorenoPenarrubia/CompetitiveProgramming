#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

vi cs;
vi dp;
vi ndp;
ll INF = 1e18;
void compute(int l, int r, int optl, int optr) {
    if(l > r) return;
    
    int m = (l+r)/2;
    ll mv = INF;
    int opt = -1;
    for(int i=optl; i <= min(optr, m); ++i) {
        ll v = dp[i]+(cs[m]-cs[i])*(m-i);
        if(v < mv) {
            opt = i;
            mv = v;
        }
    }
    ndp[m] = mv;
    compute(l, m-1, optl, opt);
    compute(m+1, r, opt, optr);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, g;
    cin >> l >> g;
    cs = vi(l+1, 0);
    for(int i=0; i < l; ++i) {
        ll c;
        cin >> c;
        cs[i+1] = cs[i]+c;
    }
    dp = vi(l+1, 0);
    ndp = vi(l+1, 0);
    for(int i=1; i <= l; ++i) dp[i] = INF;
    for(int i=0; i < g; ++i) {
        compute(0, l, 0, l);
        dp = ndp;
    }
    cout << dp[l] << endl;
    
}
