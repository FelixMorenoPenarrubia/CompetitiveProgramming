#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;

ll gcd(ll x, ll y) {
	if(y == 0) return x;
	return gcd(y, x%y);
}

bool fr_lt(ii a, ii b) {
	return a.first*b.second < a.second*b.first;
}

ii frac(ll x, ll y) {
	return ii(x/gcd(x, y), y/gcd(x, y));
}

bool rcmp(ll x, ll y) {
	return x > y;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		vi l(m);
		vvi rl(n);
		for(int i=0; i < m; ++i) {
		 	cin >> l[i];
		 	l[i]--;
		 	rl[l[i]].push_back(i);
		}
		vvi sw(m);
		for(int i=0; i < n; ++i) {
			ll a, b;
			cin >> a >> b;
			b--;
			sw[b].push_back(a);
		}

		for(int i=0; i < m; ++i) {
			sort(sw[i].begin(), sw[i].end(), rcmp);
		}

		ii ans = ii(0, 1);
		vi add = vi(n, 0);
		ll cc = 0;
		for(int i=0; i < n; ++i) {
			for(int j=0; j < (int)rl[i].size(); ++j) {
				int t = rl[i][j];
				for(int k=0; k < (int)sw[t].size(); ++k) {
					if(k < i) {
						cc += sw[t][k];
					}
					else {
						add[k] += sw[t][k];
					}
				}
			}
			cc += add[i];
			if(fr_lt(ans, frac(cc, i+1))) {
				ans = frac(cc, i+1);
			}
		}

		cout << ans.first << "/" << ans.second << "\n";

	}
}