#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("hide.in", "r", stdin);

	int n, m;
	cin >> n >> m;
	vi s(n);
	ll mins = 1e18;
	for(int i=0; i < n; ++i) {
		cin >> s[i];
		mins = min(mins, s[i]);
	}

	vvii al = vvii(n, vii());
	vi indeg(n, 0);
	int id0 = n;

	bool bad = false;
	vi candidate(n, 0);
	for(int i=0; i < m; ++i) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--;
		v--;
		if(s[u]+w == s[v]) {
			if(indeg[v] == 0) id0--;
			indeg[v]++;
		}
		else if(s[u]+w < s[v]) {
			bad = true;
		}
		else if(s[v]+w == s[u]) {
			if(indeg[u] == 0) id0--;
			indeg[u]++;
		}
		else if(s[v]+w < s[u]) {
			bad = true;
		}
		al[u].emplace_back(v, w);
		al[v].emplace_back(u, w);
		if(w == mins) {
			if(s[u] == 2*mins) candidate[u] = 1;
			if(s[v] == 2*mins) candidate[v] = 1;
		}
	}

	if(bad) {
		cout << -1 << endl;
		return 0;
	}

	for(int i=0; i < n; ++i) {
		if(candidate[i]) {

			cerr << "candidate " << i << endl;

			bool cb = false;
			int cid = 0;
			for(ii p : al[i]) {
				int u = p.first;
				ll w = p.second;
				if(s[u] > w) cb = true;
				if(indeg[u] == 0) cid++;
			}

			if(((indeg[i] == 0 && cid == id0-1) || (indeg[i] > 0 && cid == id0)) && !cb) {
				cout << i+1 << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;





}