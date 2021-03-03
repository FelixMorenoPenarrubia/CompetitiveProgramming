#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vvi al;
vvi ral;
vi vis;
vi l;
vi r;
bool cyc = false;

void dfs_cyc(int v, int c) {
	if(vis[v]) {
		if(vis[v] == c) {
			cyc = true;
		}
		return;
	}
	vis[v] = c;

	for(int u : al[v]) {
		dfs_cyc(u, c);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	al = vvi(n);
	ral = vvi(n);
	vis = vi(n);
	l = vi(n);
	r = vi(n);

	for(int i=0; i < n; ++i) {
		cin >> l[i] >> r[i];
		l[i]--;
		r[i]--;
	}

	vi indeg(n);
	vi outdeg(n);

	for(int i=0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		al[u].push_back(v);
		ral[v].push_back(u);
		indeg[v]++;
		outdeg[u]++;
	}

	/*
	int cnt_cmp = 1;
	for(int i=0; i < n; ++i) {
		if(vis[i] == 0) {
			dfs_cyc(i, cnt_cmp);
			cnt_cmp++;
		}
	}
	if(cyc) {

		cerr << "CYC" << endl;
		cout << -1 << endl;
		return 0;
	}
	*/


	queue<int> q;

	for(int i=0; i < n; ++i) {
		if(outdeg[i] == 0) q.push(i);
	}
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int u : ral[v]) {
			r[u] = min(r[u], r[v]-1);
			outdeg[u]--;
			if(outdeg[u] == 0) {
				q.push(u);
			}
		}
	}

	set<ii> lset;
	set<ii> rset;

	for(int i=0; i < n; ++i) {
		if(indeg[i] == 0) {
			if(l[i] > 0) {
				lset.emplace(l[i], i);
			}
			else {
				rset.emplace(r[i], i);
			}
		}
		if(l[i] > r[i]) {
			cout << -1 << endl;
			return 0;
		}
	}

	vi ans;

	while(!rset.empty()) {
		int v = rset.begin()->second;
		rset.erase(rset.begin());
		if(r[v] < (int)ans.size()) {
			cout << -1 << endl;
			return 0;
		}
		ans.push_back(v);

		for(int u : al[v]) {
			indeg[u]--;
			if(indeg[u] == 0) {
				lset.emplace(l[u], u);
			}
		}

		while(!lset.empty() && lset.begin()->first <= (int)ans.size()) {
			int idx = lset.begin()->second;
			lset.erase(lset.begin());
			rset.emplace(r[idx], idx);
		}
	}

	if((int)ans.size() < n) {
		cout << -1 << endl;
	}
	else {
		for(int i=0; i < n; ++i) {
			cout << ans[i]+1 << "\n";
		}
	}









}