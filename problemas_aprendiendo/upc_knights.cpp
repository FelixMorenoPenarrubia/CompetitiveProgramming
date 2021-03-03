#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll mod = 1e8+7;

vvi operator * (const vvi& a, const vvi& b) {
	int n = a.size();
	vvi r = vvi(n, vi(n, 0));
	for(int i=0; i < n; ++i) {
		for(int k=0; k < n; ++k) {
			for(int j=0; j < n; ++j) {
				r[i][j] += a[i][k]*b[k][j];
				r[i][j] %= mod;
			}
		}
	}
	return r;
}

vi operator * (const vvi& A, const vi& b) {
	int n = A.size();
	vi r = vi(n, 0);
	for(int i=0; i < n; ++i) {
		for(int j=0; j < n; ++j) {
			r[i] += A[i][j]*b[j];
			r[i] %= mod;
		}
	}
	return r;
}

vvi expo(const vvi& A, ll m) {
	int sz = A.size();
	if(m == 0) {
		vvi R = vvi(sz, vi(sz, 0));
		for(int i=0; i < sz; ++i) R[i][i] = 1;
		return R;
	}
	vvi R = expo(A, m/2);
	if(m%2 == 0) return R*R;
	else return (R*R)*A;
}

int main() {
	vector<vvi> mat(5);
	vvi initialvals = vvi(5, vi());
	for(int n=1; n <= 4; ++n) {
		mat[n] = vvi(1<<(n<<1), vi(1<<(n<<1), 0));
		initialvals[n] = vi(1<<(n<<1), 0);
		for(ll i=0; i < (1<<(n<<1)); ++i) {
			for(ll j=0; j < (1<<(n<<1)); ++j) {
				ll new_st_i = (i>>n);
				ll old_st_i = (i&((1<<n)-1));
				ll new_st_j = (j>>n);
				ll old_st_j = (j&((1<<n)-1));
				if(old_st_i == new_st_j) {
					bool good = true;
					for(ll x=0; x < n; ++x) {
						if(new_st_i&(1<<x)) {
							if(x > 0 and old_st_j&(1<<(x-1))) {
								good = false;
							}
							if(x+1 < n and old_st_j&(1<<(x+1))) {
								good = false;
							}
							if(x > 1 and new_st_j&(1<<(x-2))) {
								good = false;
							}
							if(x+2 < n and new_st_j&(1<<(x+2))) {
								good = false;
							}
						}
					}
					if(good) {
						mat[n][i][j] = 1;
					}
				}
			}
		}
		//for(int i=0; i < (1<<(n<<1)); ++i) {
		//	initialvals[n][i] = mat[n][0][i];
		//}
		initialvals[n][0] = 1;
	}
	


	ll n, m;
	while(cin >> n >> m) {
		if(m == 1) {
			cout << (1<<n) << endl;
		}
		else {
			ll ans = 0;
			vi v = (expo(mat[n], m))*initialvals[n];
			for(auto x : v) {
				ans += x;
				ans %= mod;
			}
			cout << ans << endl;
		}
	}

}