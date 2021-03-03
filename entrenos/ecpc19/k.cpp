#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll INF = 1e18;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("plants.in", "r", stdin);

	int n;
	cin >> n;

	vi h(n);
	vi g(n);
	for(ll &x : h) cin >> x;
	for(ll &x : g) cin >> x;

	if(n == 1) {
		cout << 0 << endl;
		return 0;
	}


	ll mn = 0;
	ll mx = INF;

	for(int i=0; i+1 < n; ++i) {
		if(h[i] > h[i+1]) {
			if(g[i] >= g[i+1]) {
				mn = INF+1;
				break;
			}
			else {
				ll d = (h[i]-h[i+1])/(g[i+1]-g[i]);
				if((h[i]-h[i+1])%(g[i+1]-g[i])) d++;
				mn = max(mn, d);
			}
		}
		else {
			if(g[i] > g[i+1]) {
				ll d = (h[i+1]-h[i])/(g[i]-g[i+1]);
				if((h[i+1]-h[i])%(g[i]-g[i+1])) d++;
				mx = min(mx, d);
			}
		}
	}
	if(mn > mx) cout << -1 << endl;
	else cout << mn << endl;


}