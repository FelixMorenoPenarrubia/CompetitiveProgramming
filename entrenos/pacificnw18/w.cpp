#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
	int n, m;
	cin >> n >> m;
	vi dp(m+1, 0);
	dp[m] = 1;
	for(int i=0; i < n; ++i) {
		vi ndp(m+1, 0);
		int lb = -1;
		int fr = m;
		string s;
		cin >> s;
		for(int j=0; j < m; ++j) {
			if(s[j] == 'B') {
				lb = j;
			}
			else if(s[j] == 'R' && fr == m) {
				fr = j;
			}
		}
		for(int j=lb+1; j <= fr; ++j) {
			for(int k=j; k <= m; ++k) {
				ndp[j] += dp[k];
			}
		}
		dp = ndp;
	}
	ll ans = 0;
	for(int i=0; i <= m; ++i) {
		ans += dp[i];
	}
	cout << ans << endl;

	
}