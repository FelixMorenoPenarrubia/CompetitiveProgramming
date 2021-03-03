#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi p;
vi a;
vi ans;
vi size;
vvi ch;
vvi ptu;
vvi ptd;
vii pt;
vi st;
vi lazy;

const int MAX_AG = 1e5+5;

void propagate(int q, int l, int r) {
	st[q] += lazy[q];
	if(l < r) {
		lazy[2*q] += lazy[q];
		lazy[2*q+1] += lazy[q];
	}
	lazy[q] = 0;
}

void update(int q, int l, int r, int i, int j, int v) {
	propagate(q, l, r);
	if(r < i || l > j) return;
	
	if(l >= i && r <= j) {
		lazy[q] += v;
		return;
	}
	update(2*q, l, (l+r)/2, i, j, v);
	update(2*q+1, (l+r)/2+1, r, i, j, v);
	st[q]=min(st[2*q], st[2*q+1]);
}

int query(int q, int l, int r, int i) {
	propagate(q, l, r);
	if(r < i || l > i) return 1e9;
	if(l == r) {
		return st[q];
	}
	return min(query(2*q, l, (l+r)/2, i), query(2*q+1, (l+r)/2+1, r, i));

}

void dfs_size(int v) {
	size[v] = 1;
	for(int i=0; i < (int)ch[v].size(); ++i) {
		dfs_size(ch[v][i]);
		size[v] += size[ch[v][i]];
	}
}

void dfs_up(int v, set<ii>& rset) {
	int maxidx = -1;
	for(int i=0; i < (int)ch[v].size(); ++i) {
		if(maxidx == -1 || size[ch[v][i]] > size[ch[v][maxidx]]) {
			maxidx = i;
		}
	}
	if(maxidx != -1) {
		dfs_up(ch[v][maxidx], rset);
		for(int i=0; i < (int)ch[v].size(); ++i) {
			if(i != maxidx) {
				set<ii> sset;
				dfs_up(ch[v][i], sset);
				for(auto x : sset) {
					rset.insert(x);
				}

			}
		}
	}
	for(int i=0; i < (int)ptu[v].size(); ++i) {
		rset.emplace(-pt[ptu[v][i]].second, ptu[v][i]);
	}
	int rp = 1e9;
	if(v != 0) rp = a[p[v]];
	auto it = rset.upper_bound(ii(-rp, 1e9));
	while(it != rset.end()) {
		ptd[v].push_back(it->second);
		it = rset.erase(it);
	}

}

void dfs_down(int v) {
	for(int i=0; i < (int)ptd[v].size(); ++i) {
		update(1, 0, MAX_AG, pt[ptd[v][i]].first, pt[ptd[v][i]].second, 1);
	}
	ans[v] = query(1, 0, MAX_AG, a[v]);
	for(int i=0; i < (int)ch[v].size(); ++i) {
		dfs_down(ch[v][i]);
	}
	for(int i=0; i < (int)ptd[v].size(); ++i) {
		update(1, 0, MAX_AG, pt[ptd[v][i]].first, pt[ptd[v][i]].second, -1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	p = vi(n, 0);
	a = vi(n, 0);
	ans = vi(n, 0);
	size = vi(n, 0);
	ch = vvi(n, vi());
	ptu = vvi(n, vi());
	ptd = vvi(n, vi());
	pt = vii(m);
	st = vi(4*MAX_AG, 0);
	lazy = vi(4*MAX_AG, 0);

	for(int i=0; i < n; ++i) {
		cin >> a[i] >> p[i];
		p[i]--;
		if(p[i] != i) ch[p[i]].push_back(i);
	}
	for(int i=0; i < m; ++i) {
		int o;
		cin >> o;
		o--;
		cin >> pt[i].first >> pt[i].second;
		ptu[o].push_back(i);
	}

	dfs_size(0);
	set<ii> rset;
	dfs_up(0, rset);
	dfs_down(0);

	for(auto x : ans) cout << x << " ";

	cout << endl;


}