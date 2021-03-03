#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll mod = 1e9+7;
ll fact(int n) {
	ll r = 1;
	for(ll i=1; i <= n; i++) r = (r*i)%mod;
	return r;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll n, m, x;
	cin >> n >> m >> x;
	if(n > m) {
		cout << 0 << endl;
		return 0;
	}
	vvi dp = vvi(n+1, vi(n+1, 0));
	dp[0][0] = 1;
	for(int i=0; i < m; ++i) {
		vvi ndp = vvi(n+1, vi(n+1, 0));
		for(int j=0; j <= min(ll(i), n); ++j) {
			for(int k=0; k <= j; ++k) {
				ll v = dp[j][k] % mod;
				//OPEN
				if(j < n) {
					//DON'T CLOSE
					ndp[j+1][k+1] += v;
					//CLOSE FIRST
					ndp[j+1][k] += v;
				}
				//NOT OPEN
				if(i+1 != x) {
					//NO CLOSE
					ndp[j][k] += v;
					//CLOSE FIRST
					if(k > 0) ndp[j][k-1] += v;
				}
			}
		}
		dp = ndp;
	}
	cout << ((dp[n][0]%mod )*fact(n)%mod)<< endl;
}
