#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;


vvi al;
vvi ral;

vvi scc_al;
vvi scc_ral;
int cidx = 0;
vi on_stack;
vi st;
vi num;
vi low;
vi scc;
vi fun;
vi f;
int cscc = 0;
vi dp;

void dfs_scc(int v) {
	num[v] = low[v] = cidx;
	cidx++;
	st.push_back(v);
	on_stack[v] = 1;
	for(int i=0; i < (int)al[v].size(); ++i) {
		int u = al[v][i];
		if(num[u] == -1) {
			dfs_scc(u);
		}
		if(on_stack[u]) {
			low[v] = min(low[v], low[u]);
		}
	}
	if(num[v] == low[v]) {
		int u;
		do {
			u = st.back();
			st.pop_back();
			scc[u] = cscc;
			fun[cscc] += f[u];
			on_stack[u] = 0;
		} while (u != v);
		cscc++;
	}
}

const ll INF = 1e18;

ll lpath(int v) {
	if(dp[v] == -1) {
		dp[v] = -INF;
		for(int i=0; i < (int)scc_ral[v].size(); ++i) {
			int u = scc_ral[v][i];
			dp[v] = max(dp[v], lpath(u)+fun[v]);
		}
	}
	return dp[v];
}

int main() {
	int n, m, s, e;
	cin >> n >> m >> s >> e;
	--s;
	--e;
	al = vvi(n);
	ral = vvi(n);
	f = vi(n);
	for(int i=0; i < n; ++i) cin >> f[i];

	for(int i=0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		al[u].push_back(v);
		ral[v].push_back(u);
	}

	on_stack = vi(n, 0);
	num = vi(n, -1);
	low = vi(n, -1);
	scc = vi(n, -1);
	fun = vi(n, 0);

	for(int i=0; i < n; ++i) {
		if(num[i] == -1) dfs_scc(i);
	}

	//DEBUG
/*
	for(int i=0; i < n; ++i) {
		cerr << "vertex " << i << " belongs to scc "  << scc[i] << " with fun " << fun[scc[i]] << endl; 
	}*/

	//END DEBUG

	scc_al = vvi(cscc);
	scc_ral = vvi(cscc);

	for(int v=0; v < n; ++v) {
		for(int i=0; i < (int)al[v].size(); ++i) {
			int u = al[v][i];
			if(scc[u] == scc[v]) continue;
			scc_al[scc[v]].push_back(scc[u]);
			scc_ral[scc[u]].push_back(scc[v]);
		}
	}
	dp = vi(cscc, -1);
	dp[scc[s]] = fun[scc[s]];

	

	//DEBUG

/*
	for(int i=0; i < cscc; ++i) {
		cout << " scc " << i << " has lpath " << lpath(i) << endl;
	}*/

	//END DEBUG

	cout << lpath(scc[e]) << endl;


}