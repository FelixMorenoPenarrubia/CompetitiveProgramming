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
	int n;
	cin >> n;
	vi a (n);
	for(int i=0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	if(n % 2) {
		for(int i=0; i < n; i++) {
			if(2*i < n) cout << a[2*i] << " ";
			else cout << a[n-1-(2*i)%n] << " ";
		}
	}
	else {
		for(int i=0; i < n; i++) {
			if(2*i < n) cout << a[2*i] << " ";
			else cout << a[2*n-1-2*i] << " ";
		}
	}
}
