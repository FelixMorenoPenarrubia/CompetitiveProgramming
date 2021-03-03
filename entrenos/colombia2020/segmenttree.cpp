#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

//aquest vector l'inicialitzes amb 4*n
vi st;
vi a;
int n;

void build_st(int p, int l, int r) {
	if(l == r) {
		st[p] = l;
	}
	else {
		build_st(2*p, l, (l+r)/2);
		build_st(2*p+1, (l+r)/2+1, r);
		if(a[st[2*p]] > a[st[2*p+1]]) {
			st[p] = st[2*p];
		}
		else {
			st[p] = st[2*p+1];
		}
	}
}

//retorna l'index del max
int rmq(int p, int l, int r, int i, int j) {
	if(l > j || r < i) return -1;
	if(l >= i && r <= j) {
		return st[p];
	}

	int i1 = rmq(2*p, l, (l+r)/2, i, j);
	int i2 = rmq(2*p+1, (l+r)/2+1, r, i, j);
	if(i1 == -1) return i2;
	if(i2 == -1) return i1;
	if(a[i1] > a[i2]) return i1;
	return i2;
}


void update(int p, int l, int r, int i) {
	if(l > i || r < i) return;
	if(l == i && r == i) {
		
	}
	else {
		update(2*p, l, (l+r)/2, i);
		update(2*p+1, (l+r)/2+1, r, i);
		if(a[st[2*p]] > a[st[2*p+1]]) {
			st[p] = st[2*p];
		}
		else {
			st[p] = st[2*p+1];
		}
	}
}

void update_elem(int i, int v) {
	a[i] = v;
	update(1, 0, n-1, i);
}

int range_max(int i, int j) {
	return rmq(1, 0, n-1, i, j);
}

int main() {
	cin >> n;
	int q;
	cin >> q;
	a = vi(n);
	for(auto &x : a) { 
		cin >> x;
		x *= -1;
	}

	st = vi(4*n);
	build_st(1, 0, n-1);
	int c;
	while(cin >> c) {
		if(c == 0) {
			int i, j;
			cin >> i >> j;
			cout << range_max(i, j) << endl;
		}
		else {
			int i, v;
			cin >> i >> v;
			update_elem(i, v);
		}
	}
}