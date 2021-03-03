#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
int n, m;

vvi al;
vi up;
vi dfs_minh;
vi visited;
vi bccsiz;
int br, ap, bcc, mxbcc;

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

void dfs(int v, int idx) {
	if(visited[v]) return;

	//cerr << "dfs(" << v << ", " << idx << ")" << endl;

	visited[v] = idx;
	up[v] = 0;
	bccsiz[v] = al[v].size();
	dfs_minh[v] = idx;
	int cup  = -1;
	int nc = 0;
	bool isap = false;
	for(int i=0; i < (int)al[v].size(); ++i) {
		int u = al[v][i];
		if(visited[u] == 0) {
			dfs(u, idx+1);
			dfs_minh[v] = min(dfs_minh[v], dfs_minh[u]);
			if(dfs_minh[u] == idx && !isap && idx > 1) {
				ap++;
				isap = true;
			}
			up[v] += up[u];
			bccsiz[v] += bccsiz[u];
			nc++;
		}
		else if (visited[u] > visited[v]) {
			up[v]--;
		}
		else {
			dfs_minh[v] = min(dfs_minh[v], visited[u]);
			cup++;
		}
	}


	//cerr << "v = " << v << " up[v] = " << up[v] << " cup = " << cup << endl;

	if(idx > 1) {
		
		up[v] += cup;
		if(up[v] == 0) {
			br++;
			if(bccsiz[v] >= 2) {
				bcc++;
			}
			mxbcc = max(mxbcc, bccsiz[v]-1);
			bccsiz[v] = -1;
		}
	}
	else {
		if(nc > 1) {
			ap++;
		}
		if(bccsiz[v] >= 2) {
			bcc++;
		}
		mxbcc = max(mxbcc, bccsiz[v]);
	}
}

int main() {
	int L;
	cin >> L;
	while(L--) {
		cin >> n >> m;
		al = vvi(n, vi());
		dfs_minh = vi(n, 0);
		up = vi(n, 0);
		visited = vi(n, 0);
		bccsiz = vi(n, 0);
		for(int i=0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			--u;
			--v;
			al[u].push_back(v);
			al[v].push_back(u);
		}
		br = 0;
		ap = 0;
		bcc  = 0;
		mxbcc = 2;
		dfs(0, 1);

		mxbcc /= 2;
		
		cout << ap << " " << br << " " << (br+bcc)/gcd(br+bcc, mxbcc) << " " << mxbcc/gcd(br+bcc, mxbcc) << endl;

		
	}
}