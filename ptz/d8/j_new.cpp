#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool good = true;
vvi al;
vi visited;

void dfs(int v, int cc) {
	if(visited[v] == -1) visited[v] = cc;
	else if(visited[v] == cc) return;
	else {
		good = false;
		return;
	}

	for(int u : al[v]) {
		dfs(u, cc^1);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	al = vvi(n);
	visited = vi(n, -1);
	for(int i=0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		al[v].push_back(u);
		al[u].push_back(v);
	}

	int ans = 0;
	int cc = 0;
	for(int i=0; i < n; ++i) {
		if(visited[i] == -1) {
			dfs(i, 2*cc);
			cc++;
		}
	}

	vi bans(cc);
	vi wans(cc);
	for(int i=0; i < n; ++i) {
		if(visited[i]&1) bans[visited[i]/2]++;
		else wans[visited[i]/2]++;
	}
	for(int i=0; i < cc; ++i) {
		ans += min(bans[i], wans[i]);
	}
	cout << (good ? ans : -1) << endl;

	
}