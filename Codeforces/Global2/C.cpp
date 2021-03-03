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
	int n, m;
	cin >> n >> m;
	vvi a(n, vi(m));
	vvi b(n, vi(m));
	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	bool good = true;
	for(int i=0; i < n; i++) {
		int sum = 0;
		for(int j=0; j < m; j++) {
			sum += a[i][j] + b[i][j];
		}
		if(sum % 2 != 0) good = false;
	}
	for(int i=0; i < m; i++) {
		int sum = 0;
		for(int j=0; j < n; j++) {
			sum += a[j][i] + b[j][i];
		}
		if(sum % 2 != 0) good = false;
	}
	cout << (good ? "Yes" : "No") << endl;
}
