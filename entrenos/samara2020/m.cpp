#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi al;
vi maxst;
vi minst;
vi lc;
int gc = 0;

void dfs_maxminst(int v, int p) {
	maxst[v] = v;
	minst[v] = v;
	for(int u : al[v]) {
		if(u != p) {
			dfs_maxminst(u, v);
			maxst[v] = max(maxst[v], maxst[u]);
			minst[v] = min(minst[v], minst[u]);
		}
	}
}

void dfs_c(int v, int p, int mn, int mx, int c) {
	int deg = al[v].size();
	lc[v] = c;
	if(p == -1) {
		dfs_c(al[v][0], v, v, v, 1);
		if(!(minst[al[v][0]] > v || maxst[al[v][0]] < v)) {
			lc[v] = -1e7;
		}
	}
	else if(deg == 1) {
		gc++;
		lc[v]--;
		if(!(mn > v || mx < v)) {
			lc[v] = -1e7;
		}
	}
	else if(deg == 2) {
		int u = al[v][0];
		if(u == p) u = al[v][1];
		int mnu = min(mn, v);
		int mxu = max(mx, v);
		int cu = c;
		if(mx < v || mn > v) cu++;
		if(maxst[u] < v || minst[u] > v) {
			gc++;
			lc[v]--;
			cu--;
		}
		if(!((mx < v && minst[u] > v) || (mn > v && maxst[u] < v))) {
			lc[v] = -1e7;
		}
		dfs_c(u, v, mnu, mxu, cu);
	}
	else {
		lc[v] = -1e7;
		int u1 = -1;
		int u2 = -1;
		for(int u : al[v]) {
			if(u != p) {
				if(u1 == -1) u1 = u;
				else u2 = u;
			}
		}

		int mnu1 = min(mn, min(v, minst[u2]));
		int mxu1 = max(mx, max(v, maxst[u2]));
		int cu1 = c;


		int mnu2 = min(mn, min(v, minst[u1]));
		int mxu2 = max(mx, max(v, maxst[u1]));
		int cu2 = c;


		if((maxst[u2] < v && mn > v) || (minst[u2] > v && mx < v)) {
			cu1++;
		}
		if((maxst[u1] < v && mn > v) || (minst[u1] > v && mx < v)) {
			cu2++;
		}
		if((maxst[u1] < v && minst[u2] > v) || (minst[u1] > v && maxst[u2] < v)) {
			gc++;
			lc[v]--;
			cu1--;
			cu2--;
		}

		dfs_c(u1, v, mnu1, mxu1, cu1);
		dfs_c(u2, v, mnu2, mxu2, cu2);


	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	if(n == 1) {
		cout << 1 << endl;
		return 0;
	}

	al = vvi(n, vi());
	bool good = true;
	for(int i=0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		al[u].push_back(v);
		al[v].push_back(u);
		if(al[u].size() > 3 || al[v].size() > 3) good = false;
	}

	if(good) {
		maxst = vi(n);
		minst = vi(n);
		lc = vi(n, 0);

		int root = 0;
		while(al[root].size() > 1) root++;
		dfs_maxminst(root, -1);
		dfs_c(root, -1, 1e7, -1, 0);

		vi ans;
		for(int i=0; i < n; ++i) {
		//	cerr << "i = " << i << " gc = " << gc << " lc[i] = " << lc[i] << endl;
 			if(gc+lc[i] == n-1) {
				ans.push_back(i);
			}
		}
		if(ans.size() > 0) {
			for(int i=0; i < (int)ans.size(); ++i) {
				cout << ans[i]+1 << " ";
			}
			cout << endl;
		}
		else {
			cout << "-1" << endl;
		}

	}
	else {
		cout << "-1" << endl;
	}

}