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
	int n, m, hj;
	cin >> n >> m >> hj;
	vvi h = vvi(n, vi(m, 0));
	vi a (m);
	vi b (n);
	for(int i=0; i < m; i++) cin >> a[i];
	for(int j=0; j < n; j++) cin >> b[j];
	for(int i=0; i < n; i++) {
		for (int j=0; j < m; j++) {
			int d;
			cin >> d;
			if(d == 1) h[i][j] = min(a[j], b[i]);
		}
	}
	for(int i=0; i < n; i++) {
		for (int j=0; j < m; j++) {
			cout << h[i][j] << " ";
		}
		cout << endl;
	}
}

