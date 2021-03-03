#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

const ll MOD = 998244353;
const ll mod = MOD;

ll pot(ll b, ll e) {
	if(e == 0) return 1;
	ll sq = pot(b, e/2);
	if(e&1) return (((sq*sq)%MOD)*b)%MOD;
	return (sq*sq)%MOD;
}

ll inv(ll x) {
	return pot(x, mod-2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector <ll>f(n+1);
    f[0] = 1;
    ll lsum = 0;
    for (int i = 1; i <= k; ++i) {
    	f[i] = (f[i-1]*i)%MOD;
    	lsum += f[i];
    	lsum %= MOD;
    }
    ll sum = (f[k]*k)%MOD;
    for (int i = k+1; i <= n; ++i) {
        f[i] = sum;

        sum *= (i);
        sum %= mod;
        sum *= inv(i-2);
        sum %= mod;
        sum += lsum;
        sum += (((((i)*(i-1))%MOD)*f[i])%MOD);
        sum %= mod;
        lsum += f[i];
        lsum %= mod;
        
    }
    cout << f[n] << endl;
}
