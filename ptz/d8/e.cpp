#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct res {
	int l;
	int r;
	ll x;
};

const int L = 61;

int n, k;
vector<res> v;
vvi ans;

void solve(ll exp) {

	//cerr << "Solving " << exp << endl;

	vi intdiff(n+1);
	vi intc(n, 0);
	vi zf(n+1, 0);
	vi of(n+1, 0);
	for(int i=0; i < k; ++i) {
		if(v[i].x&(1LL<<exp)) {
			intdiff[v[i].l] += 1;
			intdiff[v[i].r+1] -= 1;
		}
	}

	int cc = 0;
	for(int i=0; i < n; ++i) {
		cc += intdiff[i];
		intc[i] = cc;
		zf[i+1] = zf[i]+(cc == 0);
		of[i+1] = of[i]+(cc == 1);
	}

	bool possible = true;
	bool onerealint = true;
	bool oneint = true;
	bool zeroint = true;

	vi zcv(n);
	vi zcvdiff(n+1);

	int minl = n+1;
	int minr = n+1;
	int maxl = -1;
	int maxr = -1;
	int intid = 0;

	for(int i=0; i < k; ++i) {
		if(!(v[i].x&(1LL<<exp))) {
			if(zf[v[i].r+1] == zf[v[i].l]) {
				if(zeroint) zeroint = false;
				else onerealint = false;

				intid = i;

				if(of[v[i].r+1] > of[v[i].l]) {
					zcvdiff[v[i].l] += 1;
					zcvdiff[v[i].r+1] -= 1;
					minl = min(v[i].l, minl);
					minr = min(v[i].r, minr);
					maxl = max(v[i].l, maxl);
					maxr = max(v[i].r, maxr);
				}
				else {
					possible = false;
					oneint = false;
					//onerealint = false;
				}
			}
		}
	}

	bool entered = false;
	bool exited = false;
	int cz = 0;
	
	for(int i=0; i < n; ++i) {
		cz += zcvdiff[i];
		if(!entered and cz > 0) {
			entered = true;
			
		}
		if(entered and !exited and cz == 0) exited = true;
		if(exited and cz > 0) {
			oneint = false;
			
		}
	}
	if(zeroint) {

		//cerr << "Zero covering " << endl;

		for(int i=0; i < k; ++i) {
			ans[exp][i] = 1;
		}
	}
	else if(onerealint) {

		//cerr << "One real int " << endl;
		if(possible) {
			for(int i=0; i < k; ++i) {
				if(v[i].x&(1LL<<exp)) {
					if(v[i].r >= minl && v[i].l <= maxr) {
						if(of[v[i].r+1] > of[v[i].l]) {
							ans[exp][i] = 1;
						}
					}
				}
			}
		}
		ans[exp][intid] = 1;
	}
	else if(oneint) {

		//cerr << "One int " << endl;

		for(int i=0; i < k; ++i) {
			if(v[i].x&(1LL<<exp)) {
				if(v[i].r >= minl && v[i].l <= maxr) {
					if(of[v[i].r+1] > of[v[i].l]) {
						ans[exp][i] = 1;
					}
				}
			}
		}
	}
	else if(possible) {

		//cerr << "Multiple ints " << endl;

		for(int i=0; i < k; ++i) {
			if(v[i].x&(1LL<<exp)) {
				if(v[i].l <= minr && v[i].r >= maxl) {
					if(of[minr+1] > of[v[i].l] && of[v[i].r+1] > of[maxl]) {
						ans[exp][i] = 1;
					}
				}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	v = vector<res>(k);
	ans = vvi(L, vi(k, 0));

	for(int i=0; i < k; ++i) {
		cin >> v[i].l >> v[i].r >> v[i].x;
		v[i].l--;
		v[i].r--;
	}

	for(int i=0; i < L; ++i) {
		solve(i);
	}

	for(int i=0; i < k; ++i) {
		int ca = 1;
		for(int j=0; j < L; ++j) {
			ca &= ans[j][i];
		}
		cout << ca;
	}
	cout << endl;


	
}