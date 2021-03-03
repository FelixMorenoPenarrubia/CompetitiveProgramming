#include<bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

map<int, int> cc;
int n;
int m;

//vi par;
vi l;
vi r;
vi k;

vi mn;
vi mx;
vvi id_mn;
vvi id_mx;

int mo_block;

struct query {
	int i;
	int l;
	int r;
	int ans;
};

bool comp(const query& a, const query& b) {
	int ab = a.l/mo_block;
	int bb = b.l/mo_block;
	if(ab == bb) {
		if(ab%2) return a.r > b.r;
		return a.r < b.r;
	}
	return ab < bb;
}

void dfs_mxmn(int v) {
	mn[v] = cc[k[v]];
	mx[v] = cc[k[v]];
	if(l[v] > -1) {
		dfs_mxmn(l[v]);
		mn[v] = mn[l[v]];
	}
	if(r[v] > -1) {
		dfs_mxmn(r[v]);
		mx[v] = mx[r[v]];
	}
	id_mn[mn[v]].push_back(v);
	id_mx[mx[v]].push_back(v);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

//	par = vi(n);
	l = vi(n);
	r = vi(n);
	k = vi(n);
	mn = vi(n);
	mx = vi(n);

	set<int> keys;

	for(int i=0; i < n; ++i) {
		cin >> l[i] >> r[i] >> k[i];
		l[i]--;
		r[i]--;
		keys.insert(k[i]); 
	}

	int q;
	cin >> q;

	vector<query> vq(q);

	for(int i=0; i < q; ++i) {
		cin >> vq[i].l >> vq[i].r;
		vq[i].i = i;
		keys.insert(vq[i].l);
		keys.insert(vq[i].r);
	}

    m = 0;

	for(int x : keys) {
		cc[x] = m++;

		//cerr << x << "->" << m-1 << endl;
	}

	id_mx = vvi(m, vi());
	id_mn = vvi(m, vi());

	dfs_mxmn(0);

	mo_block = 1024;
	for(int i=0; i < q; ++i) {
		vq[i].l = cc[vq[i].l];
		vq[i].r = cc[vq[i].r];
	}

	sort(vq.begin(), vq.end(), comp);

	int cl = -1;
	int cr = -1;
	int cins = 0;
	int cfl = 0;
	int cfr = 0;

	vi cfl_par(m+1);
	for(int j=0; j < m; ++j) {
		cfl_par[j+1] = cfl_par[j]+id_mx[j].size();
	}
	vi cfr_par(m+1);
	for(int j=0; j < m; ++j) {
		cfr_par[j+1] = cfr_par[j]+id_mn[j].size();
	}



	for(int i=0; i < q; ++i) {


		//cerr << "ANSWERING QUERY " << vq[i].i << ": " << vq[i].l << " " << vq[i].r <<  endl;

		int ncl = vq[i].l;
		if(/*ncl/mo_block > cl/mo_block ||*/ cl == -1) {

		//	cerr << "NEW BLOCK" << endl;

			cr = ncl-1;
			cl = ncl;

			//POT MILLORAR
			cfl = 0;
			cfr = 0;
			cins = 0;

			/*
			for(int j=0; j < cl; ++j) {
				cfl += id_mx[j].size();
			}
			for(int j=cr+1; j < m; ++j) {
				cfr += id_mn[j].size();
			}
			*/

			cfl = cfl_par[cl];
			cfr = cfr_par[m]-cfr_par[cr+1];

		}
		int ncr = vq[i].r;

		//cerr << "VALUES BEFORE SHIFTS: cl = " << cl << " cr = " << cr << " cfl = " << cfl << " cfr = " << cfr << " cins = " << cins << endl; 

		while(cr < ncr) {
			cr++;
			for(int id : id_mx[cr]) {
				if(mn[id] >= cl) {
					cins++;
				}
			}
			cfr -= id_mn[cr].size();

		}
		while(cr > ncr) {
			for(int id : id_mx[cr]) {
				if(mn[id] >= cl) {
					cins--;
				}
			}
			
			cfr += id_mn[cr].size();
			cr--;
		}

		while(cl < ncl) {
			for(int id : id_mn[cl]) {
				if(mx[id] <= cr) {
					cins--;
				}
			}
			cfl += id_mx[cl].size();
			cl++;
		}
		while(cl > ncl) {
			cl--;
			for(int id : id_mn[cl]) {
				if(mx[id] <= cr) {
					cins++;
				}
			}
			cfl -= id_mx[cl].size();
		}


		//cerr << "VALUES AFTER SHIFTS: cl = " << cl << " cr = " << cr << " cfl = " << cfl << " cfr = " << cfr << " cins = " << cins << endl; 

		vq[i].ans = 2*(n-cfl-cfr-cins)+1;
	}

	vi ans(q);
	for(int i=0; i < q; ++i) {
		ans[vq[i].i] = vq[i].ans;
	}
	for(int i=0; i < q; ++i) {
		cout << ans[i] << '\n';
	}

	






}	