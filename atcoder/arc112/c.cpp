#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;


vvi chd;
vi siz;

void dfs_siz(int v) {
	siz[v] = 1;
	for(int u : chd[v]) {
		dfs_siz(u);
		siz[v] += siz[u];
	}
}

int dfs_score(int v) {
	int n = chd[v].size();
	//int s = siz[v];
	if(n == 0) return 1;
	vi sc(n);
	vi ch(n);
	vii act;
	int esc = 0;
	int sesc = 0;
	int nc = 0;

	int ans = 0;

	for(int i=0; i < n; ++i) {
		sc[i] = dfs_score(chd[v][i]);
		ch[i] = siz[chd[v][i]]%2;
		if(!ch[i]) {
			if(siz[chd[v][i]]-sc[i] >= sc[i]) ans += siz[chd[v][i]]-sc[i];
			else {
				esc += sc[i];
				sesc += siz[chd[v][i]]-sc[i];
			}
		}
		else {
			nc++;
			act.emplace_back(sc[i], i);
		}
	}
	

	sort(act.begin(), act.end());
	for(int i=0; i < nc; i++) {
		//cerr << v << " act[i] = " << act[i].first << endl;
		if(i%2) ans += siz[chd[v][act[i].second]]-act[i].first;
		else ans += act[i].first;
	}
	if(nc%2 == 0) ans += esc;
	else ans += sesc;

	//cerr << "score of " << v+1 << ": " << 1+ans << endl;

	return 1+ans;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	chd = vvi(n);
	for(int i=1; i < n; ++i) {
		int x;
		cin >> x;
		x--;
		chd[x].push_back(i);
	}

	siz = vi(n);
	dfs_siz(0);

	cout << dfs_score(0) << endl;




}