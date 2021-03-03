#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	vi v(n);
	for(int i=0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;
		x *= 2;
		y *= 2;
		y += x/2;
		v[i] = x-y;
	}

	


}