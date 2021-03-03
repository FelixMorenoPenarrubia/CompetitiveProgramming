#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout.setf(ios::fixed);
	cout << setprecision(9);

	int k;
	cin >> k;
	ld R;
	cin >> R;

	vector<ld> r(k);
	for(int i=0; i < k; ++i) cin >> r[i];

	ld l = 0;
	ld u = 1e9;
	while(u-l > 1e-9) {
		ld m = (l+u)/2;
		ld br = 0;
		for(int i=0; i < k; ++i) {
			br += 1.0/(1.0/r[i]+1.0/m);
		}
		if(br > R) {
			u = m;
		}
		else {
			l = m;
		}
	}

	cout << l << endl;

	
}