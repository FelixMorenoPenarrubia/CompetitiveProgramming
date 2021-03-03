#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

const ld pi = 2*acos(0.0);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(7);
	ld n, r;
	cin >> n >> r;
	cout << (r*sin(pi/n))/(1-sin(pi/n)) << endl;
}
