#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll n, k, m;
	cin >> n >> k >> m;
	vi a = vi(n);
	for(int i=0; i< n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	vi s = vi(n+1);
	s[0] = 0;
	for(int i=0; i < n; ++i) s[i+1] = s[i] + a[i];
	ll sum = s[n];
	ld sol = 0;
	for(int i=0; i< min(n, m+1); ++i) {
		ll tsum = sum-s[i];
		ll bon = min(k*(n-i), m-i);
		sol = max(sol, ld(tsum+bon)/ld(n-i));
	}
	cout.setf(ios::fixed);
	cout.precision(9);
	cout << sol << endl;
}
