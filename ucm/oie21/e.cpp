#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);

	int n;

	while(cin >> n) {
		if(n == 0) break;
		int d;
		cin >> d;
		vvi dp(d+1, vi(d+1, 0));

		int ans = 0;
		for(int i=0; i < n; ++i) {
			vvi ndp = vvi(dp);
			int l, w;
			cin >> l >> w;

			for(int a=0; a <= d; ++a) {
				for(int b=0; b <= d; ++b) {
					if(a+l <= d) {
						ndp[a+l][b] =  max(ndp[a+l][b], dp[a][b]+w);

						//cerr << "i = " << i << " ndp[" << a+l << "][" << b << "] = " << ndp[a+l][b] << endl;
					}
					if(b+l <= d) ndp[a][b+l] =  max(ndp[a][b+l], dp[a][b]+w);

				}
			}
			
			dp = ndp;
		}

		for(int i=0; i <= d; ++i) {
			for(int j=0; j <= d; ++j) {
				ans = max(ans, dp[i][j]);
			}
		}

		cout << ans << "\n";

	}
}