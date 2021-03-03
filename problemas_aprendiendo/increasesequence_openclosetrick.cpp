#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
ll mod=1e9+7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n, k;
	cin >> n >> k;
	vi a (n);
	for(int i=0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	vvi dp = vvi(n+1, vi(k+1, 0));
	dp[0][0] = 1;
	for(int i=0; i < n; ++i) {
		vvi ndp = vvi(n+1, vi(k+1, 0));
		for(int j=0; j <= i; ++j) {
			for(int l=0; l <= k; ++l) {
				
				ll v = dp[j][l];
				
				//cerr << i << " " << j << " " << l << "  =  " << v<< endl;
				
				ll nval = (i > 0) ? j*(a[i]-a[i-1]) : j*a[i];
				nval += l;
				if(nval <= k) {
					ndp[j][nval] += (j+1)*v;
					ndp[j][nval] %= mod;
					ndp[j+1][nval] += v;
					ndp[j+1][nval] %= mod;
					if(j > 0) {
						
						 ndp[j-1][nval] += j*v;
						 ndp[j-1][nval] %= mod;
						 
					}
				}
				
			}
		}
		dp = ndp;
	}
	ll sol = 0;
	for(int l=0; l <= k; ++l) {
		sol += dp[0][l];
		sol %= mod;
	}
	sol %= mod;
	cout << sol << endl;
}
