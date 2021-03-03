#include<bits/stdc++.h>

using namespace std;

#define N n
#define T par
#define P jarr
#define L depth

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m;
vvi al;


vvi chd;
vi par;
vi visited;
vi depth;
vi ap_depth;
vi up;
vi is_ap;

vvi jarr;

void dfs(int v, int d, int prev) {

	visited[v] = 1;
	depth[v] = d;
	int upfh = 0;

	for(int u : al[v]) {
		if(!visited[u]) {
			dfs(u, d+1, v);
			chd[v].push_back(u);
			par[u] = v;
			up[v] += up[u];

		}
		else if (u != prev) {
			if(depth[u] > d) {
				up[v]--;
			}
			else {
				up[v]++;
				upfh++;
			}
		}
	}
	if(up[v] == upfh) {
		is_ap[v] = 1;
	}
}

void dfs_ap_depth(int v, int d) {
	ap_depth[v] = d;
	for(int u : chd[v]) {
		if(is_ap[v]) dfs_ap_depth(u, 1);
		else dfs_ap_depth(u, d+1);
	}
}

void process3() {
  //we initialize every element in P with -1
  for (int i = 0; i < N; i++)
    for (int j = 0; 1 << j < N; j++)
      P[i][j] = -1;
  //the first ancestor of every node i is T[i]
  for (int i = 0; i < N; i++)
  P[i][0] = T[i];
  //bottom up dynamic programing
  for (int j = 1; 1 << j < N; j++)
    for (int i = 0; i < N; i++)
      if (P[i][j - 1] != -1)
        P[i][j] = P[P[i][j - 1]][j - 1];
}
int query(int p, int q) {
  int tmp, log, i;
  //if p is situated on a higher level than q then we swap them
  if (L[p] < L[q])
    tmp = p, p = q, q = tmp;
  //we compute the value of [log(L[p)]
  for (log = 1; 1 << log <= L[p]; log++);
  log--;
  //we find the ancestor of node p situated on the same level with q using the values in P
  for ( i = log; i >= 0; i--)
    if (L[p] - (1 << i) >= L[q])
      p = P[p][i];

  if (p == q) return p;
  //we compute LCA(p, q) using the values in P
  for (i = log; i >= 0; i--)
    if (P[p][i] != -1 && P[p][i] != P[q][i])
      p = P[p][i], q = P[q][i];
  return T[p];
}

void build_lca() {
	jarr = vvi(n, vi(20, 0));
	process3();
}

void build_dfs_tree() {
	visited = vi(n, 0);
	chd = vvi(n);
	par = vi(n, -1);
	depth = vi(n, 0);
	ap_depth = vi(n, n+1);
	up = vi(n, 0);
	is_ap = vi(n, 0);

	dfs(0, 1, -1);

	dfs_ap_depth(0, 0);

	build_lca();
}

int lca(int u, int v) {
	return query(u, v);
}

bool okay(int u, int v) {
	int l = lca(u, v);
	return (l == u || l == v || depth[u]-depth[l] < ap_depth[u] || depth[v] - depth[l] < ap_depth[v]);
}

void caso() {
	cin >> n >> m;

	al = vvi(n, vi());
	vii el;

	string s;
	cin >> s;

	for(int i=0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		if(s[u] == s[v]) {
			el.emplace_back(u, v);
		}
		else {
			al[u].push_back(v);
			al[v].push_back(u);
		}
	}

	build_dfs_tree();

	for(ii p : el) {
		int u = p.first;
		int v = p.second;
		if(visited[u] && visited[v]) {
			if(okay(u, v)) {
				cout << "yes\n";
				return;
			}
		}
	}

	cout << "no\n";

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int TEST;
	cin >> TEST;
	while(TEST--) {
		caso();
	}

}