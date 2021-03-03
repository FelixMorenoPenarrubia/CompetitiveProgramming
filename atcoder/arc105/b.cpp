#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;


ll gcd(ll x, ll y) {
	if(y == 0) return x;
	return gcd(y, x%y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    int n;
    cin >> n;
    ll ans;
    cin >> ans;
    for(int i=1; i < n; ++i) {
    	ll a;
    	cin >> a;
    	ans = gcd(ans, a);
    }
    cout << ans << endl;
    

}





