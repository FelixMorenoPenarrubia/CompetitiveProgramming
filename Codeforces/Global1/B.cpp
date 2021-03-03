#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	vi b = vi(n);
	for(int i=0; i <n; i++) {
		cin >> b[i];
	}
	vi s = vi(n-1);
	ll tot = b[n-1]-b[0];
	for(int i=0; i < n-1; i++) s[i] = b[i+1]-b[i];
	sort(s.begin(), s.end());
	for(int i=0; i < k-1; i++) {
		tot -= s[n-2-i];
	}
	tot += k;
	cout << tot << endl;
}
