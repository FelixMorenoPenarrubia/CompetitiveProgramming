#include<bits/stdc++.h>

using namespace std;

#define int ll

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll INF = 1e18;

signed main() {
	int n, m;

	while(cin >> n >> m) {
		if(n == 0 && m == 0) break;
		vvi a(n, vi(m, 0));
		vi minr(n, INF);
		vi maxr(n, -INF);
		vi minc(m, INF);
		vi maxc(m, -INF);
		for(int i=0; i < n; ++i) {
			for(int j=0; j < m; ++j) {
				int x;
				cin >> x;
				a[i][j] = x;
				minr[i] = min(minr[i], x);
				minc[j] = min(minc[j], x);
				maxr[i] = max(maxr[i], x);
				maxc[j] = max(maxc[j], x);
			}
		}

		bool ans = false;
		for(int i=0; i < n; ++i) {
			for(int j=0; j < m; ++j) {
				if((minr[i] == a[i][j] && maxc[j] == a[i][j])
					|| (minc[j] == a[i][j] && maxr[i] == a[i][j])) {
						ans = true;
					}
			}
		}
		cout << (ans ? "SI\n" : "NO\n");
	}
}