#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;


vvi al;
vvi ral;

vvi scc_al;
vvi scc_ral;
ll cidx = 0;
vi on_stack;
vi st;
vi visited;
vi num;
vi low;
vi scc;
vi fun;
vi f;
int cscc = 0;
vi dp;


ll dfs_scc(int v, int base_idx) {
	if(visited[v]) return 10000000;
	visited[v] = cidx;

	ll min_idx = cidx;

	cidx++;

	st.push_back(v);

	for(int i=0; i < (int)al[v].size(); ++i) {
		int u = al[v][i];
		if(visited[u]) {
			if(visited[u] >= base_idx) min_idx = min(min_idx, visited[u]);
		}
		else {
			min_idx = min(min_idx,dfs_scc(u, base_idx));
		}
	}
	if(min_idx == visited[v]) {
	/*	if(v == st.back()) {
			st.pop_back();
            visited[v] = 1e8;
		} */
	//	else {
			while(v != st.back()) {
				scc[st.back()] = cscc;
				fun[cscc] += f[st.back()];
                visited[st.back()] = 1e8;
				st.pop_back();
			}
			st.pop_back();
			scc[v] = cscc;
            visited[v] = 1e8;
            fun[cscc] += f[v];
            cscc++;
	//	}
	}
	return min_idx;

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
	visited = vi(n);

	for(int i=0; i < n; ++i) {
		if(!visited[i]) dfs_scc(i, cidx);
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