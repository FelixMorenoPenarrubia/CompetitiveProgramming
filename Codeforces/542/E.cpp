#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

vector<bool> isPrime;
vector<ll> primes;

void sieve() {
    ll LIM = 1e6;

    isPrime = vector<bool>(LIM, true);
    isPrime[1] = false;
    primes = vector<ll>();
    for(ll i=2; i < LIM; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(ll j=2*i; j < LIM; j += i) {
                isPrime[j] = false;
            }
        }
    }

}
bool primtest(ll k) {
	if(k < 1e6) return isPrime[k];
	for(int i=0; i < primes.size(); i++) {
		if(k % primes[i] == 0) return false;
	}
	return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll k;
	cin >> k;
	//sieve();
	if(k < 1e6-2) {
		cout << 2 << endl;
		cout << "-1 " << k+2 << endl;
		return 0;
	}
	for(int i=2; i <= 1000; i++) {
		if(k % i == 0 and k/i < 1e6) {
			ll x = k/i;
			ll a = (x-2*i+1)/2;
			cout << 2*i+1 << endl;
			ll b = -a+1;
			for(int j=0; j < 2*i+1; j++) {
				b *= -1;
				if(j%2) b--;
				else b++;
				cout << b<< " ";
			}
			return 0;
		}
	}
	cout << -1 << endl;
}
