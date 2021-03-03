#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ld> vld;


ld sq(ld x) {
	return x*x;
}

int main() {

	cout.setf(ios::fixed);
	cout << setprecision(4);
	ld d, t1, t2, m1, m2;
	while(cin >> d >> t1 >> t2 >> m1 >> m2) {
		cout << (d/(t1+t2))*m1 << " " << (d/(t1+t2))*m2 << endl;
		
	}
}