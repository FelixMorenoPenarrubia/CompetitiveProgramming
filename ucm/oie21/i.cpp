#include<bits/stdc++.h>

using namespace std;

#define int ll

typedef signed ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll INF = 2e9;

vvi dp;
vi c;

int f(int a, int b) {
	if(dp[a][b] != -1) return dp[a][b];
	if(a >= b-1) {
		dp[a][b] = 0;
	}
	else {
		dp[a][b] = INF;
		for(int i=a+1; i < b; ++i) {
			dp[a][b] = min(dp[a][b], f(a, i)+f(i, b)+2*(c[b]-c[a]));
		}
	}
	return dp[a][b];

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l, n;

	while(cin >> l >> n) {
		if(l == 0 && n == 0) break;
		dp = vvi(n+2, vi(n+2, -1));
		c = vi(n+2, 0);
		c[n+1] = l;
		for(int i=0; i < n; ++i) {
			cin >> c[i+1];
		}

		cout << f(0, n+1) << "\n";
	}
}