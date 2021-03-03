#include<bits/stdc++.h>

using namespace std;


#define int ll
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iiii;
typedef vector<ii> vii;


vi primes;
vi isPrime;

const ll plim = 100;

void sieve() {
	primes = vi();
	isPrime = vi(plim+1, 1);

	for(int i=2; i <= plim; ++i) {
		if(isPrime[i]) {
			primes.push_back(i);
			for(int j=2*i; j <= plim; ++j) {
				isPrime[j] = 0;
			}
		}

	}
}

int find_set(vi& dsu, int x) {
	if(dsu[x] == x) return x;
	return dsu[x] = find_set(dsu, dsu[x]);
}

void union_set(vi& dsu, int x, int y) {
	dsu[find_set(dsu, x)] = find_set(dsu, y);
}

ll gcd(ll x, ll y) {
	if(y == 0) return x;
	return gcd(y, x%y);
}

bool check_con(const vi& v) {
	int n = v.size();
	vi dsu = vi(n);
	for(int i=0; i < n; ++i) dsu[i] = i;
	for(int i=0; i < n; ++i) {
		for(int j=i+1; j < n; ++j) {
			if(gcd(v[i], v[j]) > 1) {
				union_set(dsu, i, j);
			}
		}
	}

	for(int i=0; i < n; ++i) {
		if(find_set(dsu, i) != find_set(dsu, 0)) return false;
	}
	return true;

}	

const ll limit = 2e5;


signed main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	ll primorial = 1;
	for(int n=2; n <= 30; ++n) {
		if(isPrime[n]) primorial *= n;
		bool good = false;
		vi v(n);
		cout << n << ": ";
		for(int x=0; x <= limit; ++x) {
			for(int i=0; i < n; ++i) {
				v[i] = i+1+x;
			}
			if(check_con(v)) {
				good = true;
				cout << x << endl;
				break;
			}
		}
		if(!good) {
			cout << -1 << endl;
		}
	}
}