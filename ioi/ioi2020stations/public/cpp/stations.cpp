#include "stations.h"
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vvi al;
vi rans;
int ft = 0;

ii dfs(int v, int p, int r) {

	int cmin =  1002;
	int cmax = -1;

	for(int i=0; i < (int)al[v].size(); ++i) {
		int u = al[v][i];
		if(u == p) continue;
		ii x = dfs(u, v, !r);

		//cerr << "VISITED " << u << " returned " << x.first << " " << x.second << endl;

		cmin = min(cmin, x.first);
		cmax = max(cmax, x.second);
	}

	if(cmin == 1002) {
		rans[ft] = v;
		ft++;
		return ii(ft-1, ft-1);
	}
	else {
		if(r) {
			for(int i=ft; i > cmax+1; --i) {
				swap(rans[i], rans[i-1]);
			}
			rans[cmax+1] = v;
			ft++;
		}
		else {
			for(int i=ft; i > cmin; --i) {
				swap(rans[i], rans[i-1]);
			}
			rans[cmin] = v;
			ft++;
		}
		return ii(cmin, max(cmax, ft-1));
	}


}

std::vector<int> label(int n, int k, std::vector<int> u, std::vector<int> v) {
	
	al = vvi(n, vi());
	for(int i=0; i < n-1; ++i) {
		al[u[i]].push_back(v[i]);
		al[v[i]].push_back(u[i]);
	}

	rans = vi(1001, -1);
	ft = 0;

	dfs(0, -1, 0);
	vi ans(n);
	/*for(int i=0; i < 1001; ++i) {
		if(rans[i] != -1) {
			cerr << "rans[" << i << "] = " << rans[i] << endl;
		}
	}*/
	for(int i=0; i < n; ++i) {
		ans[rans[i]] = i;
	}
	return ans;

}

int find_next_station(int s, int t, std::vector<int> c) {
	int m = c.size();
	if(m == 1) return c[0];
	bool ismax = true;
	for(int i=0; i < m; ++i) {
		if(s < c[i]) ismax = false;
	}
	if(s == 0) {
		vi otc;
		for(int i=0; i < m; ++i) {
			 otc.push_back(c[i]);
		}
		sort(otc.begin(), otc.end());
		for(int i=0; i < m; ++i) {
			if(t <= otc[i]) return otc[i];
		}
	}
	else if(ismax) {
		int minv = 1002;
		for(int i=0; i < m; ++i) minv = min(c[i], minv);
		if(t <= minv || t >= s) return minv;
		vi otc;
		for(int i=0; i < m; ++i) {
			if(c[i] != minv) otc.push_back(c[i]);
		}
		sort(otc.begin(), otc.end());
		for(int i=m-2; i > -1; --i) {
			if(t >= otc[i]) return otc[i];
		}
		return minv;
	}
	else {
		int maxv = -1;
		for(int i=0; i < m; ++i) maxv = max(c[i], maxv);
		if(t >= maxv || t <= s) return maxv;
		vi otc;
		for(int i=0; i < m; ++i) {
			if(c[i] != maxv) otc.push_back(c[i]);
		}
		sort(otc.begin(), otc.end());
		for(int i=0; i < m-1; ++i) {
			if(t <= otc[i]) return otc[i];
		}
		return maxv;
	}


}
