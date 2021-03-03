#include<bits/stdc++.h> 

using namespace std;

#define int ll

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vii edg;

int choose(int n, int k) {
	if(k == 0) return 1;
	return (n*choose(n-1, k-1))/k;
}

int choosesum(int n, int k) {
	int r = 0;
	for(int i=0; i <= k; ++i) {
		r += choose(n, i);
	}
	return r;
}

void solve(int n, int k) {
	if(n == 0) {

	}
	else if(k%2 == 0) {
		edg.emplace_back(n, n);
		solve(n-1, k/2);
	}
	else if(k > (1<<(n-1))) {
		for(int i=0; i < n; ++i) {
			edg.emplace_back(n, n-i);
		}
		solve(n-1, k-(1<<(n-1)));
	}
	else {
		k--;
		int cc = n-1;

		//cerr << "Hola" << endl;

		for(int i=1; i <= n and k > 0; ++i) {
			while(choosesum(n-i, cc) > k) {
				cc--;
			}
			k -= choosesum(n-i, cc);

			//cerr << "k aft = " << k << endl;
			//cerr << "cc aft = " << cc << endl;
			for(int j=1; j <= cc+1; ++j) {
				edg.emplace_back(i, j);
			}
		}
	}
}



signed main() {
	int n, k;
	cin >> n >> k;
	edg = vii();
	solve(n, (1<<n)-k);
	int m = edg.size();
	cout << m << endl;
	for(int i=0; i < m; ++i) {
		cout << edg[i].first << " " << edg[i].second << endl;
	}
}