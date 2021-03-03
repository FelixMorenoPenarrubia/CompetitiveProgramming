#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef VI vi;
typedef VVI vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

const ll INF = 1000000000000000000LL;

#define VEI(w,e) ((E[e].u == w) ? E[e].v : E[e].u)
#define CAP(w,e) ((E[e].u == w) ? E[e].cap[0] - E[e].flow : E[e].cap[1] + E[e].flow)
#define ADD(w,e,f) E[e].flow += ((E[e].u == w) ? (f) : (-(f)))

struct Edge { int u, v; ll cap[2], flow; };

VI d, act;

bool bfs(int s, int t, VVI& adj, vector<Edge>& E) {
  queue<int> Q;
  d = VI(adj.size(), -1);
  d[t] = 0;
  Q.push(t);
  while (not Q.empty()) {
    int u = Q.front(); Q.pop();
    for (int i = 0; i < int(adj[u].size()); ++i) {
      int e = adj[u][i], v = VEI(u, e);
      if (CAP(v, e) > 0 and d[v] == -1) {
        d[v] = d[u] + 1;
        Q.push(v);
      }
    }
  }
  return d[s] >= 0;
}

ll dfs(int u,int t,ll bot,VVI& adj,vector<Edge>& E) {
  if (u == t) return bot;
  for (; act[u] < int(adj[u].size()); ++act[u]) {
    int e = adj[u][act[u]];
    if (CAP(u, e) > 0 and d[u] == d[VEI(u, e)] + 1) {
      ll inc=dfs(VEI(u,e),t,min(bot,CAP(u,e)),adj,E);
      if (inc) {
        ADD(u, e, inc);
        return inc;
      }
    }
  }
  return 0;
}

ll maxflow(int s, int t, VVI& adj, vector<Edge>& E) {
  //for (int i=0; i<int(E.size()); ++i) E[i].flow = 0;
  ll flow = 0, bot;
  while (bfs(s, t, adj, E)) {

  	//cerr << "hola" << endl;

    act = VI(adj.size(), 0);
    while ((bot = dfs(s,t,INF, adj, E))) flow += bot;
  }
  return flow;
}

bool rcmp(ii a, ii b) {
	return a > b;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		vi a(n);
		for(int i=0; i < n; ++i) {
			cin >> a[i];
		}
		
		vi c(m);
		vii w(m);
		vvi nds(m);

		for(int i=0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			cin >> c[i];
			cin >> w[i].first;
			w[i].second = i;
			while(v >= u) {
				nds[i].push_back(v-1);
				v /= 2;
			}
		}



		sort(w.begin(), w.end(), rcmp);

		ll ans = 0;
		//ll app = 0;

		for(int z=0; z < m; ++z) {
			int i = w[z].second;
			ll mult = w[z].first;

			vvi al(2+nds[i].size());
			vector<Edge> ve;
			for(int j=0; j < (int)nds[i].size(); ++j) {
				
			}
			
			ans += mult*maxflow(0, m+n+1, al, ve);
		}

		cout << ans << "\n";

		/*for(int i=0; i < (int)al.size(); ++i) {
			for(int j=0; j < (int)al[i].size(); ++j) {
				cerr << i << " " << al[i][j] << endl;
			}
		}*/
	}
}