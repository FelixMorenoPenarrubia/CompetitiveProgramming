#include<bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<vvvd> vvvvd;
typedef vector<vvvvd> vvvvvd;
typedef vector<vvvvvd> vvvvvvd;
typedef vector<ll> vi;



vector<unordered_map<ll, vd> > dp;

const ll base = 51;


ll code(vi v) {
	
	ll cb = 1;
	ll ans = 0;
	for(auto x : v) {
		ans += x *cb;
		cb *= base;
	}
	return ans;
}
/*
vi decode(ll x, int n) {
	vi ans;
	for(int i=0; i <= n; ++i) {
		ans.push_back(x%base);
		x /= base;
	}
	return ans;
}*/

vd f(vi v, int n) {
	ll cd = code(v);
	//cerr << cd << endl;
	vd& p = dp[n][cd];
	if(p.size() > 0) return p;

	p = vd(n, 0.0);
	int mx = 0;
	for(int i=1; i <= n; ++i) {
		mx = max(v[i], mx);
	}
	int smx = -1;
	for(int i=1; i <= n; ++i) {
		if(v[i] != mx) smx = max(v[i], smx);
	}
	int s = 0;
	for(int i=1; i <= n; ++i) s += v[i];

	if(v[0] == 0 || (smx > -1 && mx-smx > v[0])) {
		
		int nummx = 0;
		for(int i=1; i <= n; ++i) {
			if(mx == v[i]) {
				nummx++;
			}
		}
		for(int i=1; i <= n; ++i) {
			if(mx == v[i]) {
				p[i-1] = 1.0/double(nummx);
			}
		}
		return p;
	}

	for(int i=1; i <= n; ++i) {
		vi nv = vi(v);
		nv[0]--;
		nv[i]++;
		vd np = f(nv, n);
		for(int j=0; j < n; ++j) {
			p[j] += np[j]*v[i]/double(s);
		}

	}


	return p;
}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout << setprecision(2);

	dp = vector<unordered_map<ll, vd>>(6);
	int n, k;
	vi a;
	while(cin >> n >> k) {

	
		a = vi(n+1);
		a[0] = k;
		for(int i=0; i < n; ++i) {
			cin >> a[i+1];
			a[0] -= a[i+1];
		}
		
		vd probs = f(a, n);


		for(int i=0; i < n; ++i) {
			cout << "pub " << i+1 << ": " << probs[i]*100 << " %\n";
		}
		
	}

}