#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef long double ld;
typedef vector<ld> vld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;



int main() {
	int n, m;
	srand(time(NULL));
	while(cin >> n >> m) {
		vvii al(n, vii());
		for(int z=0; z < m; ++z) {
			ll x, y, c;
			cin >> x >> y >> c;
			al[x].emplace_back(y, c);
			al[y].emplace_back(x, c);
		}
		ll ans = 1e9;
		for(int z=0; z < min(10, 2*n); ++z) {
			int st = rand()%n;
			vi best = vi(n, 1e9);
			best[st] = 0;
			set<ii> pq;
			vi p(n, -1);
			pq.emplace(0, st);
			while(!pq.empty()) {
				int v = (pq.begin())->second;
				ll c = (pq.begin())->first;
				pq.erase(pq.begin());
				if(c > best[v]) continue;
				for(int i=0; i < (int)al[v].size(); ++i) {
					int u = al[v][i].first;
					ll c2 = al[v][i].second;
					if(u == p[v]) continue;
					ans = min(ans, best[u]+c+c2);
					
					if(c+c2 < best[u]) {
						ans = min(ans, best[u]+c+c2);
						 pq.emplace(c+c2, u);
						best[u] = c+c2;
						p[u] = v;

					}

				}
			}
		}
		cout << ans << '\n';

	}
}