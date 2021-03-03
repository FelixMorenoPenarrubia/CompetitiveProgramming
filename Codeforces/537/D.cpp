#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;


ll mod = 1e9+7;

ll x, y;
void extendedEuclid(ll a, ll b) {
    if(b == 1) {
        x = 1;
        y = -a+1;
        return;
    }
    extendedEuclid(b, a%b);
    ll x1 = y;
    ll y1 = (x-(a/b)*y);
    x = x1;
    y = y1;
}

ll inv(ll n) {
    extendedEuclid(n, mod);
    while(x < 0) x += mod;
    while(x >= mod) x -= mod;
    return x;
}

vi fct;
ll fact(ll n) {
	if(fct[n] == -1) fct[n] = (n*fact(n-1))%mod;
	return fct[n];
}
vi invfct;
ll invfact(ll n) {
	if(invfct[n] == -1) invfct[n] = inv(fact(n));
	return invfct[n];
}

map<char, ll> cntmap;
ll m;
ll totv;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fct = vi(1e5+10, -1);
    fct[0] = 1;
	invfct = vi(1e5+10, -1);
	
	string s;
	ll q;
	cin >> s >> q;
	m = s.size();
	bool bad = false;
	for(int i=0; i < m; ++i) {
		cntmap[s[i]]++;
		if(cntmap[s[i]] > m/2) bad = true;
	}
	totv = fact(m);
	for(auto it = cntmap.begin(); it != cntmap.end(); ++it) {
		totv = (totv*(invfact(it->second)))%mod;
	}
	for(int i=0; i < q; ++i) {
		ll a, b;
		cin >> a >>b;
		a--;
		b--;
		if(bad) {
			cout << 0 << endl;
			continue;
		}
		if(s[a] == s[b]) {
			if(cntmap[s[a]] > m/2) {
				cout << 0 << endl;
			}
			else {
				ll v = cntmap[s[a]];
				cout << (2*(((((((totv * fact(m/2))%mod)*fact(m-v))%mod)*invfact(m))%mod)*invfact(m/2-v))%mod)%mod << endl;
			}
		}
		else {
			if(cntmap[s[a]]+cntmap[s[b]] > m/2) {
				cout << 0 << endl;
			}
			else {
				ll p = cntmap[s[a]];
				ll q = cntmap[s[b]];
				ll v = p+q;
				cout << (2*(((((((totv * fact(m/2))%mod)*fact(m-v))%mod)*invfact(m))%mod)*invfact(m/2-v))%mod)%mod << endl;
			}
		}
	}
}
