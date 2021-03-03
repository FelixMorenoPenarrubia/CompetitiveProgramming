#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll f(ll x) {
	ll r = 1;
	ll p10 = 1;
	do {
		p10 *= 10;
		r *= x%p10;
		r %= (x+1);
	} while(p10 <= x);
	return r;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--) {
		ll n, m;
		cin >> n >> m;
		ll ans = 0;
		do {
			if(f(n) == n) {
				ans += m*n;
				break;
			}
			else {
				n = f(n);
				ans += n;
			}
		} while(--m);
		cout << ans << endl;
	}
}