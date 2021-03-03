#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	int m;
	while(cin >> m) {
		vector<pair<pair<string, string>, double> > inp;
		set<string> stringset;
		for(int i=0; i < m; ++i) {
			string x, y;
			cin >> x >> y;
			double c;
			cin >> c;
			inp.emplace_back(make_pair(x, y), -log(c));
			stringset.insert(x);
			stringset.insert(y);

		}
		int n = 0;
		map<string, int> mp;
		for(auto x : stringset) {
			mp[x] = n;
			n++;
		}
		vector<vector<pair<int, double> > > al(n);
		for(int i=0; i < m; ++i) {
			al[mp[inp[i].first.second]].emplace_back(mp[inp[i].first.first], inp[i].second);
		}


		vector<double> cost(n, 0);
		bool act = true;
		for(int i=0; i < n and act; ++i) {
			act = false;
			vector<double> ncost(n, 0);
			for(int j=0; j < n; ++j) {
				double nc = cost[j];
				for(auto x : al[j]) {

					//cerr << "j = " << j << " x.first " << x.first << " x.second " << x.second << endl;
					nc = min(nc, cost[x.first]+x.second);
					
				}
				if(nc < cost[j]) {
						ncost[j] = nc;
						act = true;
				}
				else {
					ncost[j] = cost[j];
				}
			}
			cost = ncost;
		}
		if(act) {
			cout << "YES!!!" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}
}