#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll mod = 998244353;

ll pot(ll b, ll e, ll m) {
	if(b%m == 0) return 0;
	if(e == 0) return 1;
	//if(e == 1) return b%m;
	ll sq = pot(b, e/2, m);
	if(e%2) return ((((sq*sq)%m)*b)%m);
	return (sq*sq)%m;
}


ll inv(ll x) {
	return pot(x, mod-2, mod);
}

ll choose(ll a, ll b) {
	if(b == 0) return 1;

	return (((a*choose(a-1, b-1))%mod)*inv(b))%mod;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m, k;
	cin >> n >> m >> k;

	if(n == 1) {
		cout << pot(k, m, mod) << endl;
	}
	else if (m == 1) {
		cout << pot(k, n, mod) << endl;
	}
	else {
		ll ans = 0;
		for(int i=0; i < k; ++i) {
			ans += (pot(i+1, n, mod)-pot(i, n, mod)+mod)*pot(k-i, m, mod);
			ans %= mod;
		}
		cout << ans << endl;
	}

}