#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> edge;
typedef vector<edge> vii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;

int n, m, k;


const ll INF = 1e18;

vvi dijkstra(int start, const vvvii& al) {
	set<pair<ll, ii> > q;
	vvi dist = vvi(n, vi(k+1, INF));
	dist[start][0] = 0;
	q.emplace(0, ii(start, 0));
	while(!q.empty()) {
		ll d = q.begin()->first;
		int u = q.begin()->second.first;
		int l = q.begin()->second.second;
		q.erase(q.begin());
		if(d > dist[u][l]) continue;
		for(auto pr : al[u][l]) {
			int v = pr.first.first;
			int lp = pr.first.second;
			ll w = pr.second;
			if(dist[v][lp] > d+w) {
				dist[v][lp] = d+w;
				q.emplace(d+w, ii(v, lp));
			}
		}
	}
	return dist;
}

int main() {
	
	cin >> n >> m;
	int a, b;
	cin >> a >>b >> k;
	vvvii al;
vvvii ral;

	al = vvvii(n, vvii(k+1, vii()));
	ral = vvvii(n, vvii(k+1, vii()));

	for(int i=0; i < n; ++i) {
		for(int j=0; j < k; ++j) {
			al[i][j].emplace_back(ii(i, j+1), 0);
			ral[i][j].emplace_back(ii(i, j+1), 0);
		}
	}

	for(int i=0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		for(int j=0; j <= k; ++j) {
			al[u][j].emplace_back(ii(v, j), w);
			if(j < k) al[u][j].emplace_back(ii(v, j+1), 0);
			ral[v][j].emplace_back(ii(u, j), w);
			if(j < k) ral[v][j].emplace_back(ii(u, j+1), 0);
		}
	}

	vvi da1 = dijkstra(a, al);
	vvi da2 = dijkstra(a, ral);
	vvi db1 = dijkstra(b, al);
	vvi db2 = dijkstra(b, ral);

	ll ans = INF;
	int ansi = -1;
	for(int i=0; i < n; ++i) {
		if(i == a or i == b) continue;
		for(int j=0; j <= k; ++j) {
			for(int l=0; l <= k; ++l) {
				ll cans = da1[i][j]+da2[i][k-j]+db1[i][l]+db2[i][k-l];
				if(ans > cans) {
					ans = cans;
					ansi = i;
				}
			}
		}
	}
	if(ans == INF) {
		cout << ">:(" << endl;
	}
	else {
		cout << ansi << " " << ans <<  endl;
	}



}