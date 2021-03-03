#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MAX_VN = 1e4+5;

vvi v;
vi vis;
vi chk;
vi pv;
vi rv;
vvi dp;
vvii e;
vvii chd;

//RECORDAR TEMA N

int read() {
	int n, m, w;
	cin >> n >> m >> w;
	int id = v.size();
	v.push_back(vi());
	e.push_back(vii());
	chd.push_back(vii());
	pv.push_back(0);
	for(int i=0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		if(!vis[x]) {
			vis[x] = 1;
			v[id].push_back(x);
		}
		if(!vis[y]) {
			vis[y] = 1;
			v[id].push_back(y);
		}
		e[id].emplace_back(x, y);
	}
	for(int i=0; i < w; ++i) {
		int x, y;
		cin >> x >> y;
		if(!vis[x]) {
			vis[x] = 1;
			v[id].push_back(x);
		}
		int cid = read();
		chd[id].emplace_back(x, cid);
		pv[cid] = y;
		if(!vis[y]) {
			vis[y] = 1;
			v[cid].push_back(y);
		}
	}
	/*if(id == 1) {
		cerr << n << endl;
	}*/
	for(int i=0; i < n; ++i) {
	/*	if(id == 1) {

			cerr << "vtx: " << v[id][i] << endl;
			exit(0);
		}*/
		rv[v[id][i]] = i;
	}

	return id;
}

int read_wof(int n, int m, int w) {
	int id = v.size();
	v.push_back(vi());
	e.push_back(vii());
	chd.push_back(vii());
	pv.push_back(0);
	for(int i=0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		if(!vis[x]) {
			vis[x] = 1;
			v[id].push_back(x);
		}
		if(!vis[y]) {
			vis[y] = 1;
			v[id].push_back(y);
		}
		e[id].emplace_back(x, y);
	}
	for(int i=0; i < w; ++i) {
		int x, y;
		cin >> x >> y;
		if(!vis[x]) {
			vis[x] = 1;
			v[id].push_back(x);
		}
		int cid = read();
		chd[id].emplace_back(x, cid);
		pv[cid] = y;
		if(!vis[y]) {
			vis[y] = 1;
			v[cid].push_back(y);
		}


	}
	if(id == 1) {
		
	}
	for(int i=0; i < n; ++i) {
		//if(id == 1) {

		//	cerr << "vtx: " << v[id][i] << endl;
		//	exit(0);
		//}
		rv[v[id][i]] = i;
	}
	return id;
}

bool check(int id, int m) {

	//if(id == 1) cerr << "check(" << id << ", " << m << "):" << endl;

	//if(id == 1)cerr << "n edges: " << e[id].size() << endl;



	for(int i=0; i < (int)e[id].size(); ++i) {
	/*	if(id == 1) {
		cerr << "i = " << i << endl;
		cerr << e[id][i].first << " " << e[id][i].second << endl;
		cerr << rv[e[id][i].first] << " " << rv[e[id][i].second] << endl;
	}*/
		if((((1<<rv[e[id][i].first])&(m)) == 0) && (((1<<rv[e[id][i].second])&(m)) == 0)) return false;
	}
	return true;
}

int popcount(int x) {
	int r = 0;
	while(x > 0) {
		if(x&1) r++;
		x /= 2;
	}
	return r;
}

int f(int id, int par) {
	int& res = dp[id][par];
	if(res != -1) return res;
	res = 1e9;
	int n = v[id].size();
	for(int m=0; m < (1<<n); ++m) {
		if((par && ((m&(1<<rv[pv[id]])) == 0)) || !check(id, m)) {
			continue;
		}

	//	cerr << "f(" << id << ", " << par <<"): ac " << m << endl; 

		int cres = popcount(m);
		for(int i=0; i < (int)chd[id].size(); ++i) {
			if((1<<rv[chd[id][i].first])&m) {
				cres += f(chd[id][i].second, 0);
			}
			else {
				cres += f(chd[id][i].second, 1);
			}
		}
		res = min(res, cres);
	}
	return res;
} 

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, w;
	while(cin >> n >> m >> w) {
		v = vvi();
		pv = vi();
		e = vvii();
		chd = vvii();
		vis = vi(MAX_VN, 0);
		chk = vi(MAX_VN);
		rv = vi(MAX_VN);



		read_wof(n, m, w);

		dp = vvi(v.size(), vi(2, -1));

		

		/*for(int i=0; i < (int)v.size(); ++i) {
			f(i, 0) + f(i, 1);
		}*/

		/*for(int i=0; i < (int)v.size(); ++i) {
			cerr << "i = " << i << endl;
			cerr << "cc i mida " << v[i].size() << " " << v[i][0] << endl;
			cerr << "f(i, 0) = " << f(i, 0) << endl;
			cerr << "f(i, 1) = " << f(i, 1) << endl;
		}*/

		cout << f(0, 0) << endl;


	}
	
}