#include<bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;


signed main() {
	int n, m, t, s;

	while(cin >> n >> s >> t >> m) {
		s--;
		vvii al(n);
		for(int i=0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			u--;
			v--;
			al[v].emplace_back(u, w);
		}
		set<ii> q;
		q.emplace(0, s);
		vi vis(n, 0);
		int ans = -1;
		while(!q.empty()) {
			int v = q.begin()->second;
			int d = q.begin()->first;
			q.erase(q.begin());
			if(vis[v] || d > t) continue;
			vis[v] = 1;
			ans++;
			for(ii edg : al[v]) {
				int u = edg.first;
				int w = edg.second;
				if(!vis[u]) {
					q.emplace(d+w, u);
				}
			}
		}
		cout << ans << "\n";

	}
}