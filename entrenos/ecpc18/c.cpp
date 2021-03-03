/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll INF = 1e18;

int main() {


	freopen("transform.in", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		vi a(n);
		vi b(m);
		vi cb(m);
		for(int i=0; i < n; ++i) {
			cin >> a[i];
		}

		int ci = 1;
		map<int, int> cc;
		vi rcc(1, 0);
		vi cbcnt(1, 0);
		

		for(int i=0; i < m; ++i) {
			cin >> b[i];
			if(cc[b[i]] == 0) {
				cc[b[i]] = ci;
				rcc.push_back(b[i]);
				cbcnt.push_back(0);
				ci++;
			}
			cb[i] = cc[b[i]];
			cbcnt[cb[i]]++;
		}


		vi ca;
		vvi indices(ci+1, vi());
		vi iidx;
		for(int i=0; i < n; ++i) {
			if(cc[a[i]] > 0) {
				iidx.push_back(indices[cc[a[i]]].size());
				indices[cc[a[i]]].push_back(ca.size());
				ca.push_back(cc[a[i]]);
			}
		}

		ll ts = 0;
		vi c;

		for(int i=0; i < n; ++i) {
			ll x;
			cin >> x;
			ts += x;
			if(cc[a[i]] > 0) {
				c.push_back(x);
			}
		}

		n = ca.size();

		ll cs = 0;

		bool bad = false;

		for(int i=1; i < ci; ++i) {
			for(int j=0; j < cbcnt[i]; ++j) {
				if(j >= (int)indices[i].size()) bad = true;
				else {
					cs += c[indices[i][j]];
				}
			}
		}

		if(bad) {
			cout << "No\n";
			continue;
		}


		vi consecidx(n, -1);
		vi consecmx(n, -1);

		for(int i=0; i < n; ++i) {
			if(iidx[i]+cbcnt[ca[i]] <= (int)indices[ca[i]].size()) {
				int i2 = i;
				int dst = indices[ca[i]][iidx[i]+cbcnt[ca[i]]-1]-i;

				ll css = 0;
				/*for(int j=iidx[i]; j < iidx[i]+cbcnt[ca[i]]; ++j) {
					css += c[indices[ca[i]][j]];
				}*/
				ll mx = css;
				int mxidx = iidx[i];

				while(i2+dst < n && ca[i2] == ca[i] && ca[i2+dst] == ca[i]) {
					if(css >= mx) {
						mxidx = iidx[i2];
						mx = css;
					}
					if(i2 + dst == n-1) break;
					css -= c[i2];
					css += c[i2+dst+1];
					i2++;
				}

				consecidx[i] = mxidx;
				consecmx[i] = mx;
			}
		}

		ll ans = -INF;
		vi cidx(ci+1, 0);

		
		
		while(true) {

			for(int i=1; i < ci; ++i) {
				if(consecidx[indices[i][cidx[i]]] != -1) {

				//	cerr << "FOR value " << i << " cidx " << cidx[i] << " changes to " << consecidx[indices[i][cidx[i]]] << endl; 
				//	cerr << "cs = " << cs << " is modified by " << consecmx[indices[i][cidx[i]]] << endl;

					cs += consecmx[indices[i][cidx[i]]];
					cidx[i] = consecidx[indices[i][cidx[i]]];
					

				//	cerr << cs << endl;

				}
			}

			int cj = 0;
			int last = -1;
			for(int i=0; i < n && cj < m; ++i) {
				
				//cerr << "iteration " << i << " cj = " << cj << " ca[i] = " << ca[i] << " iidx[i] = " << iidx[i] << " cb[cj] = " << cb[cj] << endl;  
					
				if(iidx[i] >= cidx[ca[i]] && iidx[i] < cidx[ca[i]]+cbcnt[ca[i]]) {
					last = ca[i];
					if(ca[i] == cb[cj]) {

					//	cerr << "COOL" << endl;

						cj++;
					}
					else {
						break;
					}
				}
				
			}

			//cerr << "FIN" << endl;

			if(cj == m) {
				ans = max(ans, cs);
				//cerr << "ans =  " << ans << endl;
			}
			if(cidx[last]+cbcnt[last] >= (int)indices[last].size()) {
				break;
			}
			else {
				cs -= c[indices[last][cidx[last]]];
				cs += c[indices[last][cidx[last]+cbcnt[last]]];
				cidx[last]++;
			}
		}








		if(ans == -INF) cout << "No\n";
		else cout << ts-ans << "\n";
	}


}