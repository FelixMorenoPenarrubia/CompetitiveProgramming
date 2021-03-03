#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi al;
vvi ral;

int cidx = 0;
vi on_stack;
vi st;
vi visited;
vi num;
vi low;
vi scc;
vvi scc_l;
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
		scc_l.push_back(vi());
			while(v != st.back()) {
				scc[st.back()] = cscc;
                visited[st.back()] = 1e8;
                scc_l[cscc].push_back(st.back());
				st.pop_back();
			}
			st.pop_back();
			scc[v] = cscc;
            visited[v] = 1e8;
            scc_l[cscc].push_back(v);
            cscc++;
	//	}
	}
	return min_idx;

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
	visited = vi(n);
	scc = vi(n);

	for(int i=0; i < n; ++i) {
		if(!visited[i]) dfs_scc(i, cidx);
	}
	
	cout << cscc << endl;
	for(int i=cscc-1; i > -1; --i) {
		cout << scc_l[i].size() << " ";
		for(auto u : scc_l[i]) cout << u << " ";
		cout << endl;
	}

	
}
