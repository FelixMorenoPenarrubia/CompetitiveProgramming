#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll x, ll y) {
	if(y == 0) return x;
	return gcd(y, x%y);
}

int main() {
	int n;
	cin >> n;
	while(n--) {
		ll b, d;
		cin >> b >> d;
		ll g = gcd(b, d);
		ll dp = d/g;
		
		if(b%dp) cout << b/dp << '\n';
		else cout << b/dp-1 << '\n';

	}
}