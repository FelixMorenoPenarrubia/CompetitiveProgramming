#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

typedef long double ld;
const ld pi = 2*acos(0.0);

struct pt {
	ld x;
	ld y;
};

ld dist(pt a, pt b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	ld r;
	cin >> n >> r;

	vector<pt> v(n+1);

	for(int i=0; i <= n; ++i) {
		v[i].x = r*cos(i*pi/n);
		v[i].y = r*sin(i*pi/n);
	}

	ld res1 = 0.0;
	ld res2 = pi*r;

	for(int i=0; i < n; ++i) {
		res1 += dist(v[i], v[i+1]);
	}
	cout.setf(ios::fixed);
	cout << setprecision(6);
	cout << res1 <<  " " << res2 << endl;

	
}