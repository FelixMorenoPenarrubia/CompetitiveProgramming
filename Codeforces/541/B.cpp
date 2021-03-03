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
	ll a, b;
	a = 0;
	b = 0;
	ll sol = 1;
	for(int i=0; i < n; i++) {
		ll na, nb;
		cin >> na >> nb;
		if(b > na or a > nb) sol += 0;
		else sol += min(na-a, min(nb-b, min(na-b, nb-a)))+ll(a != b);
		a = na;
		b = nb;
	}
	cout << sol << endl;
}
