#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ld> vld;


ld sq(ld x) {
	return x*x;
}

int main() {
	ld l;
	int p, m, n;
	cout.setf(ios::fixed);
	cout << setprecision(4);
	while(cin >> l >> p >> m >> n) {
		vld a(m);
		vld b(n);
		for(auto &x : a) cin >> x;
		for(auto &x : b) cin >> x;

		ld ans = max(sqrt(sq(a[0]-b[n-1])+sq(l)),sqrt(sq(a[m-1]-b[0])+sq(l)));

		

		cout << ans << endl;
	}
}