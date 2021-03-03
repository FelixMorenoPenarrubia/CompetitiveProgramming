#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

const ll mod =  998244353;

int main() {


	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	ll k;
	cin >> n >> k;
	ll W = 0;
	ll C = 0;

	string s;

	cin >> s;

	for(int i=0; i < n; ++i) {
		if(s[i] == 'W') W++;
		else if(s[i] == 'C') C++;
	}

	int w = 0;
	int c = C;

	ll ans = 0;

	for(int i=0; i < n; ++i) {
		if(s[i] == 'W') w++;
		else if(s[i] == 'C') c--;
		else if(s[i] == 'A') {
			ans += (k*((w*(c+(k-1)*C))%mod))%mod;
			ans += (((mod+(W*(c+(k-1)*C)-((w*C)%mod)))%mod)*(((k*(k-1))/2)%mod))%mod;
			ans += (mod-((((W*C)%mod)*((((k-1)*(k)*(2*k-1))/6)%mod))%mod))%mod;
			ans %= mod;
		}
	}

	cout << ans << endl;


	
	

}