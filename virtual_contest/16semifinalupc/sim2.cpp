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

		int li = 0;
		int ri = m-1;
		int lj = 0;
		int rj = n-1;
		ld ans = 0;
		for(int z=0; z < p; ++z) {
			ld d1 = sqrt(sq(a[li]-b[rj])+sq(l));
			ld d2 = sqrt(sq(a[ri]-b[lj])+sq(l));
			if(d1 > d2) {
				ans += d1;
				li++;
				rj--;
			}
			else {
				ans += d2;
				lj++;
				ri--;
			}
		}

		cout << ans << endl;
	}
}