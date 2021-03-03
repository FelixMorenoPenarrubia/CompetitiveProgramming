#include<bits/stdc++.h>

using namespace std;


#define int ll
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iiii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

struct Edge {
	int x;
	int y;
	ll w;
	bool cycle;
	bool destroyed;
};

int n, m, ncol;
map<ii, Edge> el;
map<ii, int> bannededges;
vii vel;
vvi al;
vvii cycs;
vi vis_c;
vi st_c;
int cc;
int cyc;

Edge& edg(int x, int y) {
	if(x > y) swap(x, y);
	return el[ii(x, y)];
}

Edge& edg(ii x) {
	if(x.first > x.second) swap(x.first, x.second);
	return el[x];
}

void dfs_cycles(int v, int p) {

	cerr << "dfs(" << v << ", " << p << ")" << endl;

	if(vis_c[v]) {
		cycs.push_back(vii(1, ii(v, p)));
		bannededges[ii(v, p)] = 1;
		edg(ii(v, p)).cycle = 1;
		while(st_c.back() != v) {
			int u = st_c.back();
			st_c.pop_back();
			if(st_c.empty()) {
				cerr << "SOCORRO" << endl;
			}
			edg(u, st_c.back()).cycle = true;
			cycs[cyc].emplace_back(u, st_c.back());
		}
		cerr << "Created cycle of size " << cycs[cyc].size() << endl;
		cyc++;
		return;
	}
	vis_c[v] = true;
	st_c.push_back(v);
	for(auto u : al[v]) {
		if(u != p && !bannededges[ii(v, u)]) {
			dfs_cycles(u, v);
		}
	}

}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int caso=0; caso < T; ++caso) {
		cin >> n >> m >> ncol;
		el.clear();
		al = vvi(n);
		vis_c = vi(n);
		bannededges.clear();
		st_c = vi();
		cc = 0;
		cyc = 0;
		cycs = vvii();
		vel = vii();

		for(int i=0; i < m; ++i) {
			int x, y, w;
			cin >> x >> y >> w;
			x--;
			y--;
			if(x > y) swap(x, y);
			Edge e;
			e.x = x;
			e.y = y;
			e.w = w;
			e.cycle = false;
			e.destroyed = false;
			el[ii(x, y)] = e;
			al[x].push_back(y);
			al[y].push_back(x);
			vel.emplace_back(x, y);
		}

		for(int i=0; i < n; ++i) {
			if(!vis_c[i]) {
				dfs_cycles(i, -1);
				cc++;
			}
		}

		vector<iiii> v1;
		vector<iiii> v2;

		//DIFF FORMAT!!!!

		for(int i=0; i < m; ++i) {
			if(!edg(vel[i]).cycle) {
				cerr << "wololo" << endl;
				v1.emplace_back(ii(edg(vel[i]).w, 1), vel[i]);
			}
		}
		for(int i=0; i < cyc; ++i) {


			int bestj = 0;
			int sbestj = 1;



			if(edg(cycs[i][0]).w > edg(cycs[i][1]).w) swap(bestj, sbestj);
			for(int j=2; j < (int)cycs[i].size(); ++j) {
				if(edg(cycs[i][j]).w <= edg(cycs[i][bestj]).w) {
					sbestj = bestj;
					bestj = j;
				}
				else if(edg(cycs[i][j]).w <= edg(cycs[i][sbestj]).w) {
					sbestj = j;
				}
			}
			v2.emplace_back(ii(edg(cycs[i][bestj]).w+edg(cycs[i][sbestj]).w, i), ii(bestj, sbestj));

			for(int j=0; j < (int)cycs[i].size(); ++j) {
				if(j != bestj && j != sbestj) {
					cerr << "Adding to v1 edge " << cycs[i][j].first << " " << cycs[i][j].second << endl;

					v1.emplace_back(ii(edg(cycs[i][j]).w, 1), cycs[i][j]);
				}
			}


		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		int rn = ncol-cc;

		cerr << "rn = " << rn << endl;
		cerr << "v1 size " << v1.size() << endl;
		cerr << "v2 size " << v2.size() << endl;



		int i1 = 0;
		int i2 = 0;

		ll ans = 0;
		while(i1+i2 < rn) {
			if(i2 == (int)v2.size() || (i1 < (int)v1.size() && v1[i1].first.first <= v2[i2].first.first)) {
				ans += v1[i1].first.first;
				i1++;
			}
			else {
				ans += v2[i2].first.first;
				i2++;
			}
		}

		cout << ans << endl;



	}
}