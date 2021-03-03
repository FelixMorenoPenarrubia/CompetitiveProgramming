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
	vi s(n);
	for(int i=0; i < n; i++) cin >> s[i];
	sort(s.begin(), s.end());
	vi d(n-1);
	for(int i=0; i < n-1; i++) d[i] = s[i+1]-s[i];
	sort(d.begin(), d.end());
	vi ds(n, 0);
	for(int i=1; i < n; i++) ds[i] = d[i-1]+ds[i-1];
	int q;
	cin >> q;
	for(int i=0; i < q; i++) {
		ll x, y;
		cin >> x >> y;
		ll dist = y-x;
		int l = 0;
		int r = n-1;
		while(r-l > 0) {
			int m = (l+r)/2;
			if(d[m] > dist) {
				r = m;
			}
			else l = m+1;
		}
		
		
		
		int fg = l;
		l = 0;
		r = n;
		
		//cerr << "y-x = " << dist << " first distance greater = " << fg << " sum of distances up to that = " << ds[fg] << endl;
		
		
		cout << (dist+1)*(n-fg)+ds[fg] << " ";
	}
	
}
