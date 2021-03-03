#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n;
vi a;
vvi st;
vi win;
int nw = 0;

int mini(int i, int j) {
	return a[i] > a[j] ? i : j;
}

void init_rmq() {
	st = vvi(n, vi(22, 0));

	for(int i=0; i < n; ++i) {
		st[i][0] = i;
	}
	for(int i=1; (1<<i) <= n; ++i) {
		for(int j=0; j < n; ++j) {
			if(j+(1<<(i-1)) < n)st[j][i] = mini(st[j][i-1], st[j+(1<<(i-1))][i-1]);
			else st[j][i] = st[j][i-1];
		}
	}
}

int rmq(int l, int r) {
	int i = 0;
	while((1<<i) <= (r-l+1)) i++;
	i--;
	return mini(st[l][i], st[r-(1<<i)+1][i]);
}

void solve(int l, int r, int minh) {
	if(r < l) return;

	//cerr << "solve(" << l << ", " << r << ", " << minh << ")" << endl;

	int id = rmq(l, r);
	if(a[id] < minh) {
		return;
	}
	nw++;
	win[id] = 1;
	solve(l, id-1, max(a[id]-(id-l-1), minh));
	solve(id+1, r, max(a[id]-(r-id-1), minh));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	a = vi(n);
	win = vi(n, 0);
	for(int i=0; i < n; ++i) {
		cin >> a[i];
	}

	init_rmq();
	solve(0, n-1, 0);

	cout << nw << endl;
	for(int i=0; i < n; ++i) {
		if(win[i]) cout << i+1 << " ";
	}
	cout << endl;


	
}