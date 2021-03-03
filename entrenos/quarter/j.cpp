#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi a(n);
	vi b(n);
	for(int i=0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i=0; i < n; ++i) {
		cin >> b[i];
	}
	vi s(n+1);
	for(int i=0; i < n; ++i) {
		s[i+1] = s[i] + (a[i]-b[i])*(a[i]-b[i]);
	}
	int m;
	cin >> m;
	cout.setf(ios::fixed);
	cout << setprecision(10);
	for(int k=0; k < m; ++k) {
		int i, j;
		cin >> i >> j;
		cout << sqrt(s[j]-s[i-1]) << "\n";
	}
}