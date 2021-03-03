#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int INF = 1e8;

int main() {


	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a(n);
	vi b(n);
	for(int i=0; i < n; ++i) cin >> a[i] >> b[i];

	vi dp(n+2, INF);
	dp[0] = 0;
	for(int i=0; i < n; ++i) {
		vi ndp(n+2, INF);
		for(int j=0; j < i+1; ++j) {
			if(i*a[i] < dp[j]) {
				ndp[j+1] = min(ndp[j+1], dp[j]+a[i]);
			}
			else {
				ndp[j] = min(ndp[j], dp[j]+a[i]);
			}
			if(i*b[i] < dp[j]) {
				ndp[j+1] = min(ndp[j+1], dp[j]+b[i]);
			}
			else {
				ndp[j] = min(ndp[j], dp[j]+b[i]);
			}
		}
		dp = ndp;
	}
	for(int i=0; i < n; ++i) {
		if(dp[i] < INF) {
			cout << i << endl;
			break;
		}
	}

}