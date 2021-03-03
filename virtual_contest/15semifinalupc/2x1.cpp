#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;



int main() {
	int n, k;
	while(cin >> n >> k) {
		vi p(k);
		int sum = 0;
		for(auto &x : p) {
			 cin >> x;
			 sum += x;
		}
		if(n == 1) {
			cout << sum << endl;
			continue;
		}
		vi dp(sum/2+5, 0);
		dp[0] = 1;
		int ans = sum;
		for(int j=0; j < k; ++j) {
			vi ndp = vi(dp);
			for(int i=0; i <= sum/2; ++i) {
				if(i >= p[j]) {
					ndp[i] |= dp[i-p[j]];
				}
			}
			dp = ndp;
		}
		for(int i=0; i <= sum/2; ++i) {
			if(dp[i]) ans = sum-i;
		}
		cout << ans << endl;

	}

}