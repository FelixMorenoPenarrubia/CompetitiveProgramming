#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

vi cbys;
vi mincanddist;
vi secmincanddist;
vvi cand;
vi statmax;
vi statsecmax;
ll maxc;
int n, m;
ll dist(int x, int y) {
	return x > y ? (n-x)+y : y-x;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n >> m;
	cbys = vi(n, 0);
	//cand = vvi(n, vi());
	mincanddist = vi(n, 99999);
	//secmincanddist = vi(n, 99999);
	maxc = 0;
	for(int i=0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		cbys[a]++;
		maxc = max(maxc, cbys[a]);
		//cand[a].push_back(b);
		if(dist(a, b) <= mincanddist[a]) {
			//secmincanddist[a] = mincanddist[a];
			mincanddist[a] = dist(a, b);
		}
	}
	for(int i=0; i < n; i++) {
		if(cbys[i] == maxc) {
			statmax.push_back(i);
		}
		else if(cbys[i] == maxc-1 and maxc > 1) statsecmax.push_back(i);
	}
	for(int i=0; i < n; i++) {
		ll ans = (maxc-1)*n;
		ll edst = 0;
		for(int j=0; j < statmax.size(); j++) {
			
			edst = max(edst, dist(i, statmax[j])+mincanddist[statmax[j]]);
			//if(maxc > 1) edst = max(edst, secmincanddist[statmax[j]]-dist(statmax[j], i));
			//cerr << statmax[j] << " " << mincanddist[statmax[j]] << endl;
		}
		for(int j=0; j < statsecmax.size(); j++) {
			if(i == statsecmax[j]) continue;
			edst = max(edst, mincanddist[statsecmax[j]]-dist(statsecmax[j], i));
		}
		cout << ans+edst << " ";
	}
}
