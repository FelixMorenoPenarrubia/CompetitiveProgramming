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
	vvi a = vvi(n, vi(m, 0));
	vvi b = vvi(n, vi(m, 0));
	for(int i=0; i < n; i++) 
		for(int j=0; j < m; j++)
			cin >> a[i][j];
	for(int i=0; i < n; i++) 
		for(int j=0; j < m; j++)
			cin >> b[i][j];
	for(int i=0; i <= n+m-2; i++) {
		vi ad;
		vi bd;
		for(int j=max(0, i-m+1); j <= min(i, n-1); j++) {
			ad.push_back(a[j][i-j]);
			bd.push_back(b[j][i-j]);
		}
		sort(ad.begin(), ad.end());
		sort(bd.begin(), bd.end());
		if(ad != bd) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}
