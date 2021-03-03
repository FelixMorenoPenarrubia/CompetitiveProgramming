#include<bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef ll ld;

vector<ll> v;
ll d;
int n;

/*long double evaluate(long double x) {
	long double ans = 0;
	for(int i=0; i < n; ++i) {
		ans = max(ans, abs(v[i]-(x+d*i)));
	}
	return ans;
}*/

ld evaluate(ld x) {
	ld ans = 0;
	for(int i=0; i < n; ++i) {
		ans = max(ans, (ll)abs(v[i]-(x+d*i)));
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n >> d;
	d *= 2;
	v = vector<ll>(n);
	ll l = -1e17;
	ll r = 1e17;
	for(int i=0; i < n; ++i) {
		cin >> v[i];
		v[i] *= 2;
		//l = min(l, v[i]-n*d);
		//r = max(r, v[i]+n*d);
	}

//	int N = 500;

	while(r-l > 3) {

		//cerr << l << " " << r << endl;
		//cerr << r-l << endl;

		ll m1 = (2*l+r)/3;
		ll m2 = (l+2*r)/3;

		//cerr << m1 << " " << m2 << endl;

		ll a1 = evaluate(m1);
		ll a2 = evaluate(m2);
		if(a1 > a2) {
			l = m1;
		}
		else {
			r = m2;
		}
	}
	
	ll ans = 1e18;
	for(int i=0; i < 4; ++i) {
		ans = min(ans, evaluate(l+i));
	}

	cout.setf(ios::fixed);
	cout << setprecision(1);
	cout << ans/2.0 << endl;

	
}