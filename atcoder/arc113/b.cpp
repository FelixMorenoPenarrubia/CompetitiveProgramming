#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;


ll pot(ll b, ll e, ll m) {
	if(b%m == 0) return 0;
	if(e == 0) return 1;
	//if(e == 1) return b%m;
	ll sq = pot(b, e/2, m);
	if(e%2) return ((((sq*sq)%m)*b)%m);
	return (sq*sq)%m;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll a, b, c;
	cin >> a >> b >> c;


	ll ans = pot(a, pot(b, c, 4), 5);
	if(a%2) {
		if(ans%2 == 0) ans += 5; 
	}
	else {
		if(ans%2) ans += 5;
	}
	cout << ans << endl;
}