#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;


vvi al;
vi visited;
int cc = 0;

void dfs(int v) {
	if(visited[v]) return;
	visited[v] = cc;
	for(int u : al[v]) {
		dfs(u);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	//vvi mp(n, vi(m, 0));

	 al = vvi(n+m+1, vi());
	al[n+m].push_back(0);
	al[n+m].push_back(n-1);
	al[n+m].push_back(n);
	al[n+m].push_back(n+m-1);
	al[0].push_back(n+m);
	al[n-1].push_back(n+m);
	al[n].push_back(n+m);
	al[n+m-1].push_back(n+m);

	for(int i=0; i < n; ++i) {
		string s;
		cin >> s;
		for(int j=0; j < m; ++j) {
			if(s[j] == '#') {
				al[i].push_back(n+j);
				al[n+j].push_back(i);
			}

		}
	}
	visited = vi(n+m+1, 0);
	for(int i=0; i < n+m+1; ++i) {
		if(!visited[i]) {
			cc++;
			dfs(i);
		}
	}

	set<int> scr;
	set<int> scc;
	for(int i=0; i < n; ++i) {
		scr.insert(visited[i]);
	}
	for(int j=0; j < m; ++j) {
		scc.insert(visited[j+n]);
	}

	cout << min(scr.size()-1, scc.size()-1) << endl;


}