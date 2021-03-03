#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;

const int MAX_C = 2000;
vvd dp;
vd x;
vd r;
vd g;

double f(int i, int c) {

}

int main() {
	ld d;
	int l;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout << setprecision(3);
	while(cin >> d >> l) {
		dp = vvd(l+1, vd(MAX_C+1, -1.0));
		x = vd(l+1, 0);
		g = vd(l+1, 0);
		for(int i=0; i < l; ++l) {
			cin >> x[i+1] >> r[i+1] >> g[i+1];
		}

		for(int i=0; i <= l; ++i) {
			for(int c=0; c <= MAX_C; ++c) {
				if()
			}
		}

	}
}