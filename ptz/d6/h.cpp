#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

const int INF = 1e8;


ll n, m, mod;

vvi dp;
vi factdp;
vi invfactdp;
vi invdp;

ll pot(ll b, ll e) {
	if(e == 0) return 1;
	ll sq = pot(b, e/2);
	if(e&1) return (((sq*sq)%mod)*b)%mod;
	return (sq*sq)%mod;
}

ll inv(ll x) {
	return pot(x, mod-2);
}


ll invfact(ll x) {
	return invfactdp[x];
}

ll fact(ll x) {
	return factdp[x];
}

ll choose(ll a, ll b) {
	
	/*if(b == 0) return 1;
	return (((a*choose(a-1, b-1))%mod)*inv(b))%mod;
	
	return ((((fact(a)*invfact(b))%mod)*invfact(a-b))%mod);*/
	return (fact(a)*invfact(a-b))%mod;
}

ll f(ll i, ll j) {
	if(dp[i][j] != -1) return dp[i][j];
	ll& r = dp[i][j];
	r = 0;
	if(j < m) r += (((m-j)*(i)*choose(n*m-i*j-1, i-1))%mod)*f(i, j+1);
	r %= mod;
	if(i < n) r += (((n-i)*(j)*choose(n*m-i*j-1, j-1))%mod)*f(i+1, j);
	r %= mod;
	return r;
}


int main() {


	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> mod;
	dp = vvi(n+1, vi(m+1, -1));
	dp[n][m] = 1;

	factdp = vi(n*m+1, 0);
	invfactdp = vi(n*m+1, 0);
	invdp = vi(n*m+1, 0);

	factdp[0] = 1;
	factdp[1] = 1;
	invfactdp[0] = 1;
	invfactdp[1] = 1;
	invdp[1] = 1;
	for(ll i=2; i <= n*m; ++i) {
		invdp[i] = ((invdp[mod%i])*(mod-mod/i))%mod;
		factdp[i] = (factdp[i-1]*i)%mod;
		invfactdp[i] = (invfactdp[i-1]*invdp[i])%mod;
	}


	cout << ((n*m)*f(1, 1))%mod << endl;



	/*for(int i=1; i <= n*m; ++i) {
		cerr << invdp[i] << " " << inv(i) << endl;
	}*/

	/*for(int i=1; i <= n; ++i) {
		for(int j=1; j <= m; ++j) {
			cerr << "f(" << i << ", " << j << ") = " << f(i, j) << endl;
		}
	}*/
	

}