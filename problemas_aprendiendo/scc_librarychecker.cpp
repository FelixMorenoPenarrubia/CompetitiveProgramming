#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi al;
vvi ral;

int cidx = 0;
vi on_stack;
vi st;
vi num;
vi low;
vi scc;
vvi scc_l;
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
		scc_l.push_back(vi());
		do {
			u = st.back();
			st.pop_back();
			scc[u] = cscc;
			scc_l[cscc].push_back(u);
			on_stack[u] = 0;
		} while (u != v);
		cscc++;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	al = vvi(n);
	ral = vvi(n);
	for(int i=0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		al[u].push_back(v);
		ral[v].push_back(u);
	}

	on_stack = vi(n);
	num = vi(n, -1);
	low = vi(n, -1);
	scc = vi(n);

	for(int i=0; i < n; ++i) {
		if(num[i] == -1) dfs_scc(i);
	}
	
	cout << cscc << endl;
	for(int i=cscc-1; i > -1; --i) {
		cout << scc_l[i].size() << " ";
		for(auto u : scc_l[i]) cout << u << " ";
		cout << endl;
	}

	
}
