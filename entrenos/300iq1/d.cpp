#include<bits/stdc++.h>

using namespace std;

#define int ll

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

signed main() {
	int n, t;
	cin >> n >> t;
	vi a(t);
	for(auto &x : a) cin >> x;

	vi l(n);
	vi r(n);
	vi p(n);
	vvi gl(t+1);
	for(int i=0; i < n; ++i) {
		cin >> l[i] >> r[i] >> p[i];
		gl[l[i]].push_back(i);
	}
	set<ii> lset;
	set<ii> rset;
	set<ii> pset;
	vi secondround;
	vi nextl(t+1);

	int cd = 1;
	for(int i=0; i < n; ++i) {
		while(cd < l[i]) {
			nextl[cd] = l[i];
			cd++;
		}
	}
	for(int day=1; day <= t; ++day) {
		for(int i=0; i < (int)gl[day].size(); ++i) {
			lset.emplace(l[gl[day][i]], gl[day][i]);
			rset.emplace(r[gl[day][i]], gl[day][i]);
			pset.emplace(p[gl[day][i]], gl[day][i]);
		}
		while((rset.begin())->first < nextl[(lset.begin())->first]) {
			int id = rset.begin()->second;
			secondround.push_back(id);

			pset.erase(pset.find(ii(p[id],id)));
			lset.erase(lset.find(ii(l[id],id)));
			rset.erase(rset.begin(ii(r[id],id)));
		}


	}

}