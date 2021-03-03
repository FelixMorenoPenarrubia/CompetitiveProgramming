#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll absol(ll x) {
	return x > 0 ? x : -x;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	vi fp (n, -1);
	vi sp (n, -1);
	for(int i=0; i < 2*n; i++) {
		int a;
		cin >> a;
		a--;
		if(fp[a] == -1) {
			fp[a] = i;
		}
		else {
			sp[a] = i;
		}
	}
	ll sol = fp[0]+sp[0];
	for(int i=1; i < n; i++) {
		sol += absol(fp[i]-fp[i-1])+absol(sp[i]-sp[i-1]);
	}
	cout << sol << endl;
}
