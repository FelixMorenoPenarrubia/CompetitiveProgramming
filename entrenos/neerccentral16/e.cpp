#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n;
	ll k;
	cin >> n >> k;
	vi a(n);
	for(int i=0; i < n; ++i) cin >> a[i];

	int maxi = 0;
	for(int i=1; i < n; ++i) {
		if(a[i] > a[maxi]) maxi = i;
	}

	ll mod = a[maxi]+n-1;
	ll ax = a[maxi];
	ll fsum = 0;
	ll s = -(ax-1);
	for(int i=0; i < maxi; ++i) {
		fsum += a[i];
	}
	for(int i=0; i < n; ++i) {
		s += a[i]-1;
	}
	if(k < maxi) {
		cout << "KEK" << endl;
		return 0;
	}
	if(k <= fsum) {
		cout << "YES" << endl;
		return 0;
	}
	if(k-(maxi) < mod) {
		cout << "KEK" << endl;
		return 0;
	}
	if(((k-(maxi))%mod) <= s+fsum-(maxi)) {
		cout << "YES" << endl;
		return 0;
	}

	ll vk = (k-fsum);
	ll r = vk/mod;
	ll m = vk%mod;
	if(s == 0) {
		if(m == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "KEK" << endl;
		}

		return 0;
	}
	ll ad = m/s;
	if(m%s) ad++;

	if(ad <= r) {
		cout << "YES" << endl;
	}
	else {
		cout << "KEK" << endl;
	}


}