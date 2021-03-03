#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iiii;
typedef vector<ii> vii;




int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for(int caso=0; caso < T; ++caso) {
		int n;
		cin >> n;
		vii or_pos(n);
		set<int> xs;
		set<int> ys;
		for(int i=0; i < n; ++i) {
			cin >> or_pos[i].first >> or_pos[i].second;
			xs.insert(or_pos[i].first);
			ys.insert(or_pos[i].second);
		}

		map<int, int> xm;
		map<int, int> ym;
		int cntx  =0;
		for(auto x : xs) {
			xm[x] = cntx;
			cntx++;
		}
		int cnty = 0;
		for(auto y : ys) {
			ym[y] = cnty;
			cnty++;
		}
		vii pos(n);
		vvi pos_atx(cntx);
		vvi pos_aty(cnty);
		vi pcx(cntx);
		vi pcy(cnty);
		ll mpcx = 0;
		ll mpcy = 0;
		for(int i=0; i < n; ++i) {
			pos[i] = ii(xm[or_pos[i].first], ym[or_pos[i].second]);
			pos_atx[pos[i].first].push_back(pos[i].second);
			pos_aty[pos[i].second].push_back(pos[i].first);
			pcx[pos[i].first]++;
			pcy[pos[i].second]++;
		}
		for(int i=0; i < cntx; ++i) {
			mpcx = max(mpcx, pcx[i]);
		}
		for(int i=0; i < cnty; ++i) {
			mpcy = max(mpcy, pcy[i]);
		}

		ll nmpcx = 0;
		ll nmpcy = 0;
		ll nspcx = 0;
		ll nspcy = 0;

		vi pmx(cnty);
		vi psx(cnty);
		vi pmy(cntx);
		vi psy(cntx);

		ll ansm = 0;
		ll anss = 0;
		//ll anssd = 0;

		for(int i=0; i < cntx; ++i) {
			if(pcx[i] == mpcx) {
				nmpcx++;
				for(auto y : pos_atx[i]) {
					pmx[y]++;
				}
			}
			else if(pcx[i] == mpcx-1) {
				nspcx++;
				for(auto y : pos_atx[i]) {
					psx[y]++;
				}
			}
		}

		for(int i=0; i < cnty; ++i) {
			if(pcy[i] == mpcy) {
				nmpcy++;
				for(auto x : pos_aty[i]) {
					pmy[x]++;
				}
			}
			else if(pcy[i] == mpcy-1) {
				nspcy++;
				for(auto x : pos_aty[i]) {
					psy[x]++;
				}
			}
		}

		for(int i=0; i < cntx; ++i) {
			if(pcx[i] == mpcx) {
				ansm += (nmpcy-pmy[i]);
				anss += (nspcy-psy[i])+pmy[i];
				
			}
			else if(pcx[i] == mpcx-1) {
				anss += (nmpcy-pmy[i]);
			}
		}

		if(ansm > 0) {
			if(mpcx == 1 && mpcy == 1) ansm /= 2;
			cout << "Case " << caso+1 << ": " << mpcx+mpcy << " " << ansm << "\n";
		}
		else {
			cout << "Case " << caso+1 << ": " << mpcx+mpcy-1 << " " << anss << "\n";
		}
		


		
	}
}