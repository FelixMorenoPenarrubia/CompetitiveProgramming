#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
ll mod = 1e9+7;
ll powr(ll b, ll x) {
	if(x == 0) return 1;
	return (b*powr(b, x-1))%mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi cc = vi(27, 0);
    ll sol = 0;
    
    for(int i=0; i < n; i++) {
		ll cs = 1;
		for(char c = 'a'; c <= 'z'; c++) {
			int j = int(c-'a');
			if(c == s[i]) {
				
			}
			else {
				cs *= (cc[j]+1);
				cs %= mod;
			}
		}
		sol += cs;
		sol %= mod;
		cc[s[i]-'a']++;
	}
	cout << sol << endl;

}
