#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ld> vld;


ll absol(ll x) {
	return (x > 0) ? x : -x;
}

ld sq(ld x) {
	return x*x;
}
int main() {
	ll l;
	int p, m, n;
	
	cout.setf(ios::fixed);
	cout.precision(4);
	while(cin >> l >> p >> m >> n) {
		vector<ll> a(m);
		vector<ll> b(n);
		for(int i=0; i < m; ++i) {
			cin >> a[i];
		}
		for(int i=0; i < n; ++i) {
			cin >> b[i];
		}

		int j = 0;
		ll mind = absol(a[0]-b[0]);
		for(int i=0; i < m; ++i) {
			while(j < n-1 and absol(a[i]-b[j+1]) < absol(a[i]-b[j])) {
				j++;
				
			}
			mind = min(mind, absol(a[i]-b[j]));
		}
		
		cout << sqrt(ld(sq(mind)+sq(l))) << endl;
	}
}