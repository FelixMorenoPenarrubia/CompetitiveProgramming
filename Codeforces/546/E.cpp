#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

vi st;
vb lazy_st;
vi wst;
int n;
vi a;
vi d;
vi k;
vi kpsum;
vi kpsumsum;
ll left(ll p) {
    return 2*p;
}
ll right(ll p) {
    return 2*p+1;
}
ll parent(ll p) {
    return (p-p%2)/2;
}

void build(ll p, ll l, ll r) {
    if(l == r) {
        st[p] = d[l];
        wst[p] = (n-l)*d[l];
        return;
    }

    build(left(p), l, (l+r)/2);
    build(right(p), (l+r)/2+1, r);
    st[p] = st[left(p)] + st[right(p)];
    wst[p] = wst[left(p)] + wst[right(p)];
}
ll rsq(ll p, ll l, ll r, ll i, ll j) {

    if(i > r || j < l || lazy_st[p]) return 0;
    if(l>=i && r<=j) return st[p];
    ll s1 = rsq(left(p), l, (l+r)/2, i, j);
    ll s2 = rsq(right(p), (l+r)/2+1, r, i, j);
    return s1 + s2;
    
}
ll weight_rsq(ll p, ll l, ll r, ll i, ll j) {

    if(i > r || j < l || lazy_st[p]) return 0;
    if(l>=i && r<=j) return wst[p];
    ll s1 = weight_rsq(left(p), l, (l+r)/2, i, j);
    ll s2 = weight_rsq(right(p), (l+r)/2+1, r, i, j);
    return s1 + s2;
    
}
void set_lazy(ll p, ll l, ll r, ll i, ll j) {

    if(i > r || j < l || lazy_st[p]) return;
    if(l>=i && r<=j) {
		lazy_st[p] = true;
		st[p] = 0;
		wst[p] = 0;
		return;
	}
    set_lazy(left(p), l, (l+r)/2, i, j);
    set_lazy(right(p), (l+r)/2+1, r, i, j);
    
     st[p] = st[left(p)]+st[right(p)];
	wst[p] = wst[left(p)]+wst[right(p)];
    
}
void propagate_lazy(ll p, ll l, ll r) {
	lazy_st[p] = false;
	/*st[p] = 0;
	wst[p] = 0;*/
	if(l != r) {
		/*
		set_lazy(1, 0, n-1, l, (l+r)/2);
		set_lazy(1, 0, n-1, (l+r)/2+1, r);
		* */
		lazy_st[right(p)] = true;
		st[right(p)] = 0;
		wst[right(p)] = 0;
		
		lazy_st[left(p)] = true;
		st[left(p)] = 0;
		wst[left(p)] = 0;
		
		
	}
}

void update_point(ll p, ll l, ll r, ll ind, ll x) {
    if(l > ind || r < ind) return;
     if(lazy_st[p]) propagate_lazy(p, l, r);
    if(l == r) {
        st[p] += x;
        wst[p] += (n-l)*x;
        return;
    }
   
    update_point(left(p), l, (l+r)/2, ind, x);
    update_point(right(p), (l+r)/2+1, r, ind, x);

    st[p] = st[left(p)]+st[right(p)];
	wst[p] = wst[left(p)]+wst[right(p)];
}

void update_query(int i, ll x) {
	update_point(1, 0, n-1, i, x);
	int l = i+1;
	int r = n-1;
	while(r-l > 0) {
		int d = (l+r)/2;
		ll s = rsq(1, 0, n-1, i+1, d);
		if (s <= x) {
			l = d+1;
		}
		else {
			r = d;
		}
	}
	if(l > i+1 and l < n) {
		if(l == n-1 and rsq(1, 0, n-1, i+1, n-1) <= x) {
			set_lazy(1, 0, n-1, i+1, n-1);
		}
		else {
			update_point(1, 0, n-1, l, rsq(1, 0, n-1, i+1, l-1)-x); 
			set_lazy(1, 0, n-1, i+1, l-1);
			
		}
	}
	else if(l == n) {
		set_lazy(1, 0, n-1, i+1, n-1);
	}
	else if(l == i+1) {
		if(rsq(1, 0, n-1, i+1, i+1) > x)update_point(1, 0, n-1, l, -x);
		else set_lazy(1, 0, n-1, i+1, i+1);
	}
	
}
ll sum(int r) {
	if(r == -1) return 0;
	return weight_rsq(1, 0, n-1, 0, r)-rsq(1, 0, n-1, 0, r)*(n-(r+1))+kpsumsum[r];
}
ll sum_query(int l, int r) {
	return sum(r)-sum(l-1);
}
void debug(ll p, ll l, ll r) {
	cout << "(" << l << ", " << r << "): " << st[p] << " " << wst[p] << " " << lazy_st[p] << endl;
	if(l == r) {
		
	}
	else {
		debug(left(p), l, (l+r)/2);
		debug(right(p), (l+r)/2+1, r);
	}
}
void debug_st() {
	debug(1, 0, n-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
	a =vi(n);
	for(int i=0; i < n; i++) cin >> a[i];
	k =vi(n-1);
	for(int i=0; i < n-1; i++) cin >> k[i];
	kpsum = vi();
	ll ckpsum = 0;
	for(int i=0; i < n-1; i++) {
		kpsum.push_back(ckpsum);
		ckpsum += k[i];
	}
	kpsum.push_back(ckpsum);
	kpsumsum = vi();
	ckpsum = 0;
	for(int i=0; i < n; i++) {
		ckpsum += kpsum[i];
		kpsumsum.push_back(ckpsum);
		
	}
	//kpsumsum.push_back(ckpsum);
	int q;
	cin >> q;
	d = vi(n);
	d[0] = a[0];
	for(int i=1; i < n; i++) d[i] = a[i]-(a[i-1]+k[i-1]);
	st = vi(4*n, 0);
	wst = vi(4*n, 0);
	build(1, 0, n-1);
	lazy_st = vb(4*n, false);
	
	for(int i=0; i < q; i++) {
		char c;
		cin >> c;
		if(c == '+') {
			ll idx, x;
			cin >> idx >> x;
			idx--;
			update_query(idx, x);
		}
		else if (c == 's') {
			ll l, r;
			cin >> l >> r;
			l--;
			r--;
			ll ans = sum_query(l, r);
			if(ans == -82) cerr << "HORROR " << l << " " << r << endl;
			cout << ans << endl;
		}
		else {
			debug_st();
		}
	}
}
