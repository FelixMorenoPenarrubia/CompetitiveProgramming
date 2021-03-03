#include<bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

vii v;
const ll INF = 1e18;
vii lc;


bool ask(ii f, ii g, ll w) {
	return f.first*w+f.second > g.first*w+g.second;
}

ll query_lc(int p, int l, int r, ll i) {
	ll ans = i*lc[p].first+lc[p].second;
	if(l < r) {
		int m = (l+r)/2;
		ll sans;
		if(i <= m) sans = query_lc(2*p, l, m, i);
		else sans = query_lc(2*p+1, m+1, r, i);
		ans = max(ans, sans);
	}
	return ans;

}

void add_lc(int p, int l, int r, ii i) {
	ii j = lc[p];
	if(l == r) {
		if(ask(i, j, l)) {
			lc[p] = i;
		}
	}
	else {
		int m = (l+r)/2;
		bool al = ask(i, j, l);
		bool am = ask(i, j, m);
		if(al && am) {
			lc[p] = i;
			add_lc(2*p+1, m+1, r, j);
		}
		else if(al && !am) {
			add_lc(2*p, l, m, i);
		}
		else if(!al && am) {
			lc[p] = i;
			add_lc(2*p, l, m, j);
		}
		else {
			add_lc(2*p+1, m+1, r, i);
		}

	}
}

void init_lc(int n) {
	lc = vii(4*n, ii(0, -INF));
}


signed main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	v = vii(n);
	vi typc(n);
	vi visc(n);
	vi mintyp(n, INF);
	vi maxtyp(n, -INF);
	for(int i=0; i < n; ++i) {
	 	cin >> v[i].second >> v[i].first;
	 	v[i].second--;
	 	typc[v[i].second]++;
	 	mintyp[v[i].second] = min(v[i].first, mintyp[v[i].second]);
	 	maxtyp[v[i].second] = max(v[i].first, maxtyp[v[i].second]);
	}

	sort(v.begin(), v.end());
	
	vi vs(n+1);
	vi vm(n+1);
	map<ii, int> rp;
	for(int i=0; i < n; ++i) {
		rp[v[i]] = i;
	 	vs[i+1] = vs[i]+v[i].first;
	 	vm[i+1] = max(vm[i], (typc[v[i].second] > 1) ? maxtyp[v[i].second] : -INF);
	}
	vi ans1(n);
	multiset<ll> gt;
	int subc = 0;
	for(int i=0; i < n; ++i) {
		if(i > 0) ans1[i] = ans1[i-1];
		if(vm[i+1] > vm[i]) ans1[i] += (vm[i+1]-vm[i])*subc;
		gt.insert(v[i].first);
		while(!gt.empty() && vm[i+1] > *(gt.begin())) {
			ans1[i] += vm[i+1]-*(gt.begin());
			subc++;
			gt.erase(gt.begin());
		}
		
		//cerr << ans1[i] << endl;

	}

	vi ans(n);
	init_lc(n+1);
	for(int i=n-1; i > -1; --i) {
		

		//cerr << query_lc(1, 0, n, i+1) << endl;

		ll ans2 = query_lc(1, 0, n, i+1)-vs[i];
		

		ll ca = max(ans1[i], ans2);
		ans[i] = ca+vs[n];
		visc[v[i].second]++;
		if(visc[v[i].second] > 1) add_lc(1, 0, n, ii(maxtyp[v[i].second], -v[i].first));
	}
	for(int i=0; i < n; ++i) {
		cout << ans[i] << '\n';
	}

	
}