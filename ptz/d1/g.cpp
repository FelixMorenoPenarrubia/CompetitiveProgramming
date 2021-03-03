#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

const ll mod = 1e9+7;
//const int max_n = 1e6+1;

vvi al;
vi visited;
//vi in_cycle;
//vi cycle;
//vi leaves;

vi cycle_lens;
vi a;
/*
vvi operator *(vvi a, vvi b) {
	int n = a.size();
	vvi c(n, vi(n, 0));
	for(int i=0; i < n; ++i) {
		for(int j=0; j < n; ++j) {
			for(int k=0; k < n; ++k) {
				c[i][j] += a[i][k]*b[k][j];
				c[i][j] %= mod;
			}
		}
	}
	return c;
}*/

ll pot(ll b, ll e) {
	if(e == 0) return 1;
	ll sq = pot(b, e/2);
	if(e&1) return (((sq*sq)%mod)*b)%mod;
	return (sq*sq)%mod;
}
/*
vvi mat_pot(const vvi& m, ll e) {
	if(e == 0) {
		vvi id = vvi(2, vi(2, 0));
		id[0][0] = 1;
		id[1][1] = 1;
		return id;
	}
	vvi sq = mat_pot(m, e/2);
	if(e&1) return (((sq*sq))*m);
	return (sq*sq);
}

ll ac(ll i, ll k) {
	if(i == 1) return 1;
	if(i == 2) return 0;
	vvi amt = vvi(2, vi(2, 0));
	amt[0][0] = k-1;
	amt[0][1] = k-2;
	amt[1][1] = 1;
	vvi mt = mat_pot(amt, i-2);

	for(int i=0; i < 2; ++i) {
		for(int j=0; j < 2; ++j) {
			cerr << mt[i][j] << " ";
		}
		cerr << endl;
	}
	return (mt[0][0]);

}*/

void compute_a(ll n, ll k) {
	a = vi(n+2);
	a[1] = 1;
	a[2] = 0;

	for(int i=3; i <= n+1; ++i) {
		a[i] = (a[i-2]*(k-1))%mod + (a[i-1]*(k-2))%mod;
		a[i] %= mod;
		//if(a[i] != ac(i, k)) cerr << "ERROR " << i << endl;
	}
}



ii dfs_cycle(int v, int p) {


	int repr = -1;
	int dst = 0;
	visited[v] = 1;

	for(int u: al[v]) {
		if(u != p) {
			if(visited[u]) {
				if(repr == -1) { 
					//in_cycle[v] = 1;
					//cycle.push_back(v);
					repr = u;
				}
			}
			else {
				ii r = dfs_cycle(u, v);
				if(r.first != -1) {
					repr = r.first;
					dst = r.second;
					//in_cycle[v] = 1;
					//cycle.push_back(v);
				}
			}
		}
	}
	if(repr == v) {
		cycle_lens.push_back(dst+1);
		return ii(-1, 0);
	}
	return ii(repr, dst+1);
}




int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	

	int T;
	cin >> T;
	while(T--) {
		int n, m;
		ll k;
		cin >> n >> m >> k;

		compute_a(n, k);

		al = vvi(n);
		visited = vi(n);
		cycle_lens = vi();

		for(int i=0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			al[u].push_back(v);
			al[v].push_back(u);
		}

		dfs_cycle(0, -1);

		ll ans = k;

		ll non_cyc = n-1;
		for(int i=0; i < (int)cycle_lens.size(); ++i) {
			non_cyc -= (cycle_lens[i]-1);
			ans *= a[cycle_lens[i]+1];
			ans %= mod;
		}
		//ans *= pot(k-1, non_cyc);
		for(int i=0; i < non_cyc; ++i) {
			ans *= k-1;
			ans %= mod;
		}
		//ans %= mod;

		cout << ans << "\n";





		
		

	}
}