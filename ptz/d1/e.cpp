#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout.setf(ios::fixed);
	cout << setprecision(3);

	int T;
	cin >> T;
	while(T--) {
		ld C;
		cin >> C;
		int n;
		cin >> n;
		ld mx = 1e18;
		ld mn = 0;
		for(int i=0; i < n; ++i) {
			ld x, y;
			cin >> x >> y;
			x /= C;
			y /= C;
			ld g = 5.0/C;
			ld disc = x*x-4*g*x*x*(g*x*x+y);
			//cerr << disc << endl;
			ld cmx = (x+sqrt(disc))/(2*g*x*x);
			ld cmn = (x-sqrt(disc))/(2*g*x*x);

			mx = min(cmx, mx);
			mn = max(cmn, mn);

		}
		cout << (mx+mn)/2.0 << "\n";
	}
}