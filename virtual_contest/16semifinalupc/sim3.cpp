#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ld> vld;


ld sq(ld x) {
	return x*x;
}
ll sqi(ll x) {
	return x*x;
}

int main() {
	ll l;
	int p, m, n;
	cout.setf(ios::fixed);
	cout << setprecision(4);
	while(cin >> l >> p >> m >> n) {
		vector<ll> a(m);
		vector<ll> b(n);
		for(auto &x : a) cin >> x;
		for(auto &x : b) cin >> x;

		ld ans = sqrt(sq(a[0]-b[0])+sq(l));

		int cj = 0;
		for(int i=0; i < m; ++i) {
			ll d = sqi(a[i]-b[cj])+sqi(l);
			while(cj < n-1 and d > sqi(a[i]-b[cj+1])+sqi(l)) {
				cj++;
				d = sqi(a[i]-b[cj])+sqi(l);
			}
			ans = min(ans, sqrt(ld(d)));
		}

		cout << ans << endl;
	}
}