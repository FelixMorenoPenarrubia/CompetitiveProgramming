#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;


ll INF = 1e18;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, l;
	cin >> n >> l;
	vi a(n+2);
	vi b(n+2);
	for(int i=0; i < n; ++i) cin >> a[i+1];
	for(int i=0; i < n; ++i) cin >> b[i+1];	

	a[0] = 0;
	b[0] = 0;
	a[n+1] = l+1;
	b[n+1] = l+1;

	ll ans =  0;

	vi fx;
	for(int i=0; i < n+2; ++i) {
		if(a[i] == b[i]) fx.push_back(i);
	}
	int m = fx.size();
	bool good = true;
	for(int i=0; i < m-1; ++i) {

		cerr << fx[i] << " " << a[fx[i]] << " " << fx[i+1] << " " << a[fx[i+1]] << endl;
		if(fx[i]+1 == fx[i+1]) continue;
		int left = fx[i+1]-1;
		for(ll j=fx[i]+1; j < fx[i+1]; ++j) {
			if(b[j] > a[j]) {
				left = j-1;
				break;
			}
		}

		
		int tidx =  left;
		for(int j=left; j > fx[i]; --j) {
			if(tidx < j) {
				a[j] = a[tidx] + j-tidx;
			}
			int low = fx[i];
			int high = j;
			while(high > low+1) {
				int mid = (high+low)/2;
				if(a[mid]+j-mid <= b[j]) {
					low = mid;
				}
				else {
					high = mid;
				}
			}
			ans += j-low;
			tidx = low;
		}

		tidx =  left+1;
		for(int j=left+1; j < fx[i+1]; ++j) {
			if(tidx > j) {
				a[j] = a[tidx] - (tidx-j);
			}
			int low = j;
			int high = fx[i+1];
			while(high > low+1) {
				ll mid = (high+low)/2;
				if(a[mid]-(mid-j) >= b[j]) {
					high = mid;
				}
				else {
					low = mid;
				}
			}
			ans += high-j;
			tidx = high;
		}

		
		set<ll> st;
		st.insert(a[fx[i]]-fx[i]);
		for(int j=fx[i]+1; j <= left; ++j) {
			if(st.find(b[j]-j) == st.end()) {

				cerr << "fail in " << j << " " << b[j] << endl;
				good = false;
			}
			st.insert(a[j]-j);
		}
		st.clear();
		st.insert(a[fx[i+1]]-fx[i+1]);
		for(int j=fx[i+1]-1; j > left; --j) {
			if(st.find(b[j]-j) == st.end()) {
				cerr << "fail in r " << j << " " << b[j] << endl;

				good = false;
			}
			st.insert(a[j]-j);
		}
	}
	if(good) cout << ans << endl;
	else cout << -1 << endl;


}





