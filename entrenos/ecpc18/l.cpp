#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi st;
vector<bool> lazy;
vector<bool> lm;
vi la;

int n = 100001;
const int F = -1e9;

void build_st(int p, int l, int r) {
	if(l == r) {
		st[l] = l;
	}
	else {
		build_st(2*p, l, (l+r)/2);
		build_st(2*p+1, (l+r)/2+1, r);
	}
}

void init_st() {
	st = vi(n, 0);
	lazy = vector<bool>(4*n, 0);
	lm = vector<bool>(4*n, 0);
	la = vi(4*n, 0);
	build_st(1, 0, n-1);
}

void propagate(int p, int l, int r) {
	if(lazy[p]) {
		if(l == r) {

			if(lm[p]) st[l] = -st[l]+la[p];
			else st[l] = st[l]+la[p];
		}
		else {
			lm[2*p] = lm[2*p] xor lm[p];
			if(lm[p]) la[2*p] *= -1;
			la[2*p] += la[p];
			lazy[2*p] = 1;
			lm[2*p+1] = lm[2*p+1] xor lm[p];
			if(lm[p]) la[2*p+1] *= -1;
			la[2*p+1] += la[p];
			lazy[2*p+1] = 1;
		}
		lazy[p] = 0;
		lm[p] = 0;
		la[p] = 0;
	}
}

int query(int p, int l, int r, int i) {
	if(l > i || r < i) return F;
	propagate(p, l, r);
	if(l == i && r == i) {
		return st[l];
	}
	else {
		if(i <= (l+r)/2) return query(2*p, l, (l+r)/2, i);
		return query(2*p+1, (l+r)/2+1, r, i);
	}
}

void update(int p, int l, int r, int i, int j, bool m, int a) {
	if(l > j || r < i) return;
	propagate(p, l, r);
	if(l >= i && r <= j) {
		lazy[p] = true;
		lm[p] = m;
		la[p] = a;
	}
	else {
		update(2*p, l, (l+r)/2, i, j, m, a);
		update(2*p+1, (l+r)/2+1, r, i, j, m, a);
	}
}



int main() {


	freopen("reflection.in", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--) {
		init_st();
		int q;
		cin >> q;
		for(int i=0; i < q; ++i) {
			int x;
			cin >> x;
			int y = query(1, 0, n-1, x);
			cout << y << "\n";
			update(1, 0, n-1, x, n-1, 1, 2*y);
		}
	}


}