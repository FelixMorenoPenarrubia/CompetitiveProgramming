#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;

const ll mod = 1e9+7;


ll pot(ll b, ll e) {
	if(e == 0) return 1;
	ll sq = pot(b, e/2);
	return (e%2) ? (((sq*sq)%mod)*b)%mod : (sq*sq)%mod;
}

ll inv(ll x) {
	return pot(x%mod, mod-2);
}

vi factorials;

ll choose(ll a, ll b) {
	return factorials[a]*inv(factorials[b]*factorials[a-b]);
}


int main() {
	int T;
	cin >> T;
	factorials = vi(1e5+1);
	factorials[0] = 1;
	for(ll i=1; i <= 1e5; ++i) {
		factorials[i] = (factorials[i-1]*i)%mod;
	}
	while(T--) {
		int a, b;
		cin >> a >> b;
		cout << (2*choose(a-1, b))%mod << endl;
	}

}