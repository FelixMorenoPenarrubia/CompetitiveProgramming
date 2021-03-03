#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ll gcd(ll x, ll y) {
	if(y == 0) return x;
	return gcd(y, x%y);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		map<ii, ll> sl;
		map<pair<ii, ll>, ll> ov;
		for(int i=0; i < n; ++i) {
			ll x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if(x1 == x2) {
				sl[ii(1, 0)]++;
				ov[make_pair(ii(1, 0), x1)]++;
			}
			else {

				ll num = (y2-y1);
				ll den = (x2-x1);
				if(den < 0) {
					num *= -1;
					den *= -1;
				}
				ll d = gcd(num, den);
				num /= d;
				den /= d;
				sl[ii(num, den)]++;	
				ov[make_pair(ii(num, den), den*y1-num*x1)]++;		
			}
		}
		ll ans = 0;
		for(auto x : ov) {
			ans += x.second*(x.second-1);
		}
		for(auto x : sl) {
			ans += x.second*(n-x.second);
		}
		cout << ans/2 << "\n";
	}
}