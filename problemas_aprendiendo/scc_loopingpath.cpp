#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int cidx =1;

int dfs_scc(int v, const vvi& al, vi& visited, vi& st, vi& res, int base_idx) {
	if(visited[v]) return 0;
	visited[v] = cidx;

	int min_idx = cidx;

	cidx++;

	st.push_back(v);

	for(int i=0; i < (int)al[v].size(); ++i) {
		int u = al[v][i];
		if(visited[u]) {
			if(visited[u] >= base_idx) min_idx = min(min_idx, visited[u]);
		}
		else {
			dfs_scc(u, al, visited, st, res, base_idx);
		}
	}
	if(min_idx == visited[v]) {
		if(v == st.back()) {
			st.pop_back();
		}
		else {
			while(v != st.back()) {
				res[st.back()] = 1;
				st.pop_back();
			}
			st.pop_back();
			res[v] = 1;
		}
	}
	return min_idx;

}

void dfs(int v, const vvi& al, vi& visited) {
	if(visited[v]) return;
	visited[v] = 1;
	for(int i=0; i < (int)al[v].size(); ++i) {
		int u = al[v][i];
		dfs(u, al, visited);
	}
}

int main() {
	int n, m;
	while(cin >> n >> m) {
		vvi al(n, vi());
		vvi ral(n, vi());
		for(int i=0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			al[u].push_back(v);
			ral[v].push_back(u);
		}

		int x, y;
		cin >> x >> y;
		vi visited = vi(n);
		visited[x] = n+5;
		visited[y] = n+5;
		vi res = vi(n);
		vi st = vi();
		

		cidx = 1;

		for(int i=0; i < n; ++i) {
			if(!visited[i]) {
				dfs_scc(i, al, visited, st, res, cidx);
			}
		}

		vi visited_x = vi(n);
		vi visited_y = vi(n);
		dfs(x, al, visited_x);
		dfs(y, ral, visited_y);

		bool ans = false;
		for(int i=0; i < n; ++i) {
			ans = ans || (visited_x[i] && visited_y[i] && res[i]);
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
}