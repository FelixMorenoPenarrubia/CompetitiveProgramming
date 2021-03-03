#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ld> vld;
typedef vector<ll> vi;

ld sq(ld x) {
	return x*x;
}
ld square_root(ld x) {
	ld s = x;
	for(int i=0; i < 1000; ++i) {
		s = (s + x/s)/2;
	}
	return s;
}

ll absol(ll x) {
	return (x > 0) ? x : -x;
}

bool possible(const vi& a, const vi& b, ll bound, int p) {
	int m = a.size();
	int n = b.size();
	int j = 0;
	int cnt = 0;
	for(int i=0; i < m and j < n and cnt < p; ++i) {
		while(j < n-1 and absol(a[i]-b[j]) > bound and absol(a[i]-b[j+1]) < absol(a[i]-b[j])) {
			j++;
		}
		if(absol(a[i]-b[j]) <= bound) {
			cnt++;
			j++;
		}

	//	cerr << "i = " << i << " j = "  << j << " cnt = " << cnt << endl;
	}
	return cnt >= p;
}

int main() {
	ll l;
	int p, m, n;
	cout << fixed;
	while(cin >> l >> p >> m >> n) {
		vi a(m);
		vi b(n);
		for(auto &x : a) cin >> x;
		for(auto &x : b) cin >> x;

		ll low = 0;
		ll upp = 1e7;
		while(upp > low) {
			ll mid = (upp+low)/2;
			if(possible(a, b, mid, p)) {
				upp = mid;
			}
			else {
				low = mid+1;
			}
		}

		cout << setprecision(4) << square_root(low*low+l*l) << endl;


		

		
	}
}