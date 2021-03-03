#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vvi al;

vi dp1;
vi dp2;
vii edg;

void dfs(int v, int p) {

	int sum = 0;
	int cc = 0;
	int nc = 0;
	vi ncv;
	for(int u : al[v]) {
		if(u != p) {
			dfs(u, v);
			cc++;
			if(dp2[u] <= dp1[u]) {
				sum += dp1[u];
				nc++;
				ncv.push_back(u);
			}
			else {
				sum += dp2[u];
			}
		}
	}
	if(cc == 0) {
		dp1[v] = 0;
		dp2[v] = -1;
	}
	else {
		if(nc == 0) {
			dp1[v] = sum;
			dp2[v] = sum;
		}
		else {
			dp1[v] = sum+nc/2;
			dp2[v] = sum+(nc-1)/2+1;
			if(nc%2 == 0 || p == -1) {
				for(int i=0; i < nc/2; ++i) {
				//	cerr << "emplacing at " << v << endl;
					edg.emplace_back(ncv[2*i], ncv[2*i+1]);
				}
			}
			else {
				for(int i=0; i < nc/2; ++i) {
				//	cerr << "emplacing at " << v << endl;
					edg.emplace_back(ncv[2*i], ncv[2*i+1]);
				}
		//		cerr << "emplacing at " << v << endl;
				edg.emplace_back(ncv[nc-1], p);
			}
		}
	}

//	cerr << v << " " << dp1[v] << " " << dp2[v] << endl;
}


int main() {


	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin >> n;
	al = vvi(n);
	dp1 = vi(n, 0);
	dp2 = vi(n, 0);
	for(int i=0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		al[u].push_back(v);
		al[v].push_back(u);
	}

	dfs(0, -1);

	cout << dp1[0] << "\n";
	assert(dp1[0] == (int)edg.size());
	for(int i=0; i < (int)edg.size(); ++i) {
		cout << edg[i].first+1 << " " << edg[i].second+1 << "\n";
	}
	


	
	

}