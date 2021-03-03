#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;
typedef vector<ii> vii;

const int INF = 1e9;

int n, m;
vvi al;
vi col;
vi comp;
bool good;
int cc;

void dfs(int v, int c) {
	if(col[v] != -1) {
		if(col[v] != c) good = false;
		return;
	} 
	col[v] = c;
	comp[v] = cc;
	for(auto u : al[v]) {
		dfs(u, c^1);
	}
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for(int caso=0; caso < T; ++caso) {
		
		cin >> n >> m;
		al = vvi(n, vi());
		col = vi(n, -1);
		comp = vi(n, 0);
		good = true;
		cc = 0;
		for(int i=0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			--x;
			--y;
			al[x].push_back(y);
			al[y].push_back(x);
		}

		for(int i=0; i < n; ++i) {
			if(col[i] == -1) {
				dfs(i, 0);
				cc++;
			}
		}

		vi l(n);
		vi r(n);
		for(int i=0; i < n; ++i) cin >> l[i] >> r[i];

		vii le(cc, ii(INF, 0));
		vii re(cc, ii(INF, 0));
		for(int i=0; i < n; ++i) {
			if(col[i] == 0) {
				le[comp[i]].first = min(le[comp[i]].first, l[i]);
				le[comp[i]].second = max(le[comp[i]].second, l[i]);
				re[comp[i]].first = min(re[comp[i]].first, r[i]);
				re[comp[i]].second = max(re[comp[i]].second, r[i]);
			}
			else {
				le[comp[i]].first = min(le[comp[i]].first, r[i]);
				le[comp[i]].second = max(le[comp[i]].second, r[i]);
				re[comp[i]].first = min(re[comp[i]].first, l[i]);
				re[comp[i]].second = max(re[comp[i]].second, l[i]);
			}
		}

		if(!good) {
			cout << "Case " << caso+1 << ": IMPOSSIBLE" << endl;
			continue;
		}
		vector<iiii> v;

		int cmin = INF;
		int cmax = 0;
		for(int i=0; i < cc; ++i) {
			if((le[i].first <= re[i].first) == (le[i].second <= re[i].second)) {
				v.emplace_back(ii(min(le[i].first, re[i].first), min(le[i].second, re[i].second)), ii(max(le[i].first, re[i].first), max(le[i].second, re[i].second)));
			}
			else {
				v.emplace_back(ii(max(le[i].first, re[i].first), min(le[i].second, re[i].second)), ii(max(le[i].first, re[i].first), min(le[i].second, re[i].second)));
			}
			cmin = min(cmin, v.back().first.first);
			cmax = max(cmax, v.back().first.second);
		}
		sort(v.begin(), v.end());

		/*for(int i=0; i < cc; ++i) {
			cerr << "i = " << i << endl;
			cerr << "v[i] = {" << v[i].first.first << ", " << v[i].first.second << ", " << v[i].second.first << ", " << v[i].second.second << "}" << endl;
		}*/

		int ans = cmax-cmin;
		int scmin = INF;
		for(int i=0; i < cc; ++i) {
			//cerr << "i = " << i << " cmax = " << cmax << " cmin = " << cmin << endl;
			//if(v[i].first.first == v[i].second.first) break;
			cmax = max(cmax, v[i].second.second);
			scmin = min(scmin, v[i].second.first);
			if(i+1 < cc) cmin = min(scmin, v[i+1].first.first);
			else cmin = scmin;
			
			ans = min(ans, cmax-cmin);
			if(cmin >= scmin) break;
		}
		cout << "Case " << caso+1 << ": " << ans << endl;
	}
}