#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int cidx =1;

void tarjanSCC(int u) {
dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
S.push_back(u); // stores u in a vector based on order of visitation
visited[u] = 1;

for (int j = 0; j < (int)al[u].size(); j++) {
int v = al[u][j];
if(v == x or v == y) continue;

if (dfs_num[v] == UNVISITED)
tarjanSCC(v);
if (visited[v]) // condition for update
dfs_low[u] = min(dfs_low[u], dfs_low[v]);

  }

if (u != x and dfs_low[u] == dfs_num[u]) { 
int cnt = 0;
while (1) {
++cnt;
int v = S.back(); S.pop_back(); visited[v] =0;
scc[v] = true;
if (u == v) break; }
if(cnt == 1) scc[u] = 0;
}

int dfs_scc(int v, const vvi& al, vi& visited, vi& st, vi& res, int base_idx) {
	if(visited[v]) return 10000000;
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
		min_idx = min(min_idx,dfs_scc(u, al, visited, st, res, base_idx));
		}
	}
	if(min_idx == visited[v]) {
		if(v == st.back()) {
			st.pop_back();
            visited[v] = 1e8;
		}
		else {
			while(v != st.back()) {
				res[st.back()] = 1;
                visited[st.back()] = 1e8;
				st.pop_back();
			}
			st.pop_back();
			res[v] = 1;
            visited[v] = 1e8;
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
		
		//res[x] = 0;
        //res[y] = 0;

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
