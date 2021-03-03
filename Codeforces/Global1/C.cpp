#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll pow2(ll e) {
	if(e == 0) return 1;
	return 2*pow2(e-1);
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int q;
	cin >> q;
	vi maxdiv = vi(26, 1);
	for(int i=0; i < 26; i++) {
		ll p = pow2(i)-1;
		for(int j=2; j*j < p; ++j) {
			if(p % j == 0) {
				maxdiv[i] = p/j;
				break;
			}
		}
	}
	for(int i=0; i < q; i++) {
		ll a;
		cin >> a;
		ll j = 0;
		while(pow2(j) <= a) j++;
		if(a == pow2(j)-1) {
			cout << maxdiv[j] << endl;
		}
		else cout << pow2(j)-1 << endl;
	}
}
