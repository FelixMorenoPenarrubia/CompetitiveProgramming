#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll n, k, a, b;
vi v;
ll pow2(ll e) {
	if(e == 0) return 1;
	return 2*pow2(e-1);
}
ll rec(ll l, ll r) {
	//cerr << "doing range (" << l << ", " << r << ")" << endl;
	
	ll d = (l+r)/2;
	
	auto f1 = lower_bound(v.begin(), v.end(), l);
	auto f2 = lower_bound(v.begin(), v.end(), d+1);
	auto u1 = upper_bound(v.begin(), v.end(), d);
	auto u2 = upper_bound(v.begin(), v.end(), r);
	if(l == r) {
		if(f1 == v.end() or *f1 > l) {
			//cerr << "it is void" << endl;
			 return a;
		 }
		auto bnd = equal_range(v.begin(), v.end(), l);
		
		return b*(bnd.second-bnd.first);
	}
	if(f1 != v.end() and *f1 <= d and f2 != v.end() and *f2 <= r) {
		//cerr << "both parts have avg" << endl;
		return rec(l, d) + rec(d+1, r);
	}
	else if((f1 == v.end() or *f1 > d) and (f2 == v.end() or *f2 > r)) {
		//cerr << "it is void" << endl;
		return a;
	}
	else if ((f1 == v.end() or *f1 > d)) {
		return min(rec(l, d) + rec(d+1, r), b*(u2-f2)*(r-l+1)); 
	}
	else {
		return min(rec(l, d) + rec(d+1, r), b*(u1-f1)*(r-l+1)); 
	}
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n >> k >> a >> b;
	v = vi(k);
	for(int i=0; i < k; ++i){
		 cin >> v[i];
		 v[i]--;
	 }
	sort(v.begin(), v.end());
	cout << rec(0, pow2(n)-1);
	
}
