#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll INF = 1e18;
const ll mod = 1e9+7;

ll pot(ll b, ll e) {
	if(e==0) return 1;
	ll sq = pot(b, e/2);
	if(e&1) return (((((sq*sq)%mod)*b)%mod));
	return (sq*sq)%mod;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("plants.in", "r", stdin);

	int T;
	cin >> T;

	while(T--) {
		ll n;
		cin >> n;
		cout << (pot(2, 2*n+1)-pot(2, n)+mod)%mod << endl;
	}

}