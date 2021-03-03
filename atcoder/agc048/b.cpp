#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;


ll INF = 1e18;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vi a(n);
	vi b(n);
	for(int i=0; i < n; ++i) cin >> a[i];
	for(int i=0; i < n; ++i) cin >> b[i];

	vi dp(4, 0);
	//dp[0] = -INF;
	dp[2] = -INF;
	dp[3] = -INF;

	for(int i=0; i < n; ++i) {
		vi ndp(4, 0);
		if(i%2 == 0) {
			ndp[0] = max(dp[0]+b[i], dp[3]+a[i]);
			ndp[1] = dp[1]+b[i];
			ndp[2] = max(dp[2]+b[i], dp[1]+a[i]);
			ndp[3] = dp[3]+b[i];
		}
		else {
			ndp[0] = dp[0]+b[i];
			ndp[1] = max(dp[2]+a[i], dp[1]+b[i]);
			ndp[2] = dp[2]+b[i];
			ndp[3] = max(dp[0]+a[i], dp[3]+b[i]);
		}
		dp = ndp;

		cerr << i << endl;
		cerr << dp[0] << " " << dp[1] << " " << dp[2] << " " << dp[3] << endl;
	}

	cout << max(dp[0], dp[1]) << endl;


}





