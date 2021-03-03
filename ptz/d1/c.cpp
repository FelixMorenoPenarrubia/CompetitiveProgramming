#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;


vvi al;
vi visited;
vi in_cycle;
vi cycle;
vi leaves;


int dfs_cycle(int v, int p) {


	int repr = -1;
	visited[v] = 1;

	for(int u: al[v]) {
		if(u != p) {
			if(visited[u]) {
				if(repr == -1) { 
					in_cycle[v] = 1;
					cycle.push_back(v);
					repr = u;
				}
			}
			else {
				int r = dfs_cycle(u, v);
				if(r != -1) {
					repr = r;
					in_cycle[v] = 1;
					cycle.push_back(v);
				}
			}
		}
	}
	if(repr != v) return repr;
	return -1;
}

int dfs_leaves(int v, int p) {
	int r = 0;
	for(int u: al[v]) {
		if(u != p && !in_cycle[u]) {
			r += dfs_leaves(u, v);
		}
	}
	if(al[v].size() == 1) r++;
	return r;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	

	int T;
	cin >> T;
	while(T--) {

		int n;
		cin >> n;

		al = vvi(n);
		visited = vi(n);
		in_cycle = vi(n);
		leaves = vi(n);
		cycle = vi();

		for(int i=0; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			--u;
			--v;
			al[u].push_back(v);
			al[v].push_back(u);
		}

		dfs_cycle(0, -1);

		for(int i=0; i <(int)cycle.size(); ++i) {
			leaves[cycle[i]] = dfs_leaves(cycle[i], -1);
			//cerr << cycle[i] << endl;
		}

		int ans = 0;
		bool onev = false;
		//bool stwov = false;
		bool twov = false;
		for(int i=0; i < (int)cycle.size(); ++i) {
			if(leaves[cycle[i]] == 0) onev = true;
			if(i+1 < (int)cycle.size()) {
				if(leaves[cycle[i]] == 0 && leaves[cycle[i+1]] == 0) {
					twov = true;
				}
			}
			else {
				if(leaves[cycle[i]] == 0 && leaves[cycle[0]] == 0) {
					twov = true;
				}
			}
			ans += leaves[cycle[i]];
		}

		if(twov) ans += 2;
		else if(onev) ans += 1;


		cout << max(ans, 3) << "\n";




		

	}
}