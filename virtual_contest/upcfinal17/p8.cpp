#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll mod = 1e9+7;

ll powm(ll b, ll e) {
    if(e == 0) return 1;
    ll sq = powm(b, e/2);
    return (e&1) ? (((sq*sq)%mod)*b)%mod : (sq*sq)%mod;
}
ll inv(ll a) {
    return powm(a, mod-2);
}


int main() {
    string s;
    while(cin >> s) {
        reverse(s.begin(), s.end());
        int n = s.length();
        vi hash(n);
        vi rhash(n+1);
        hash[0] = ll(s[0]-'a'+1);
        rhash[n-1] = ll(s[n-1]-'a'+1);
        rhash[n] = 0;
        for(int i=1; i < n; ++i) {
            hash[i] = hash[i-1]+ll(s[i]-'a'+1)*powm(31, i);
            hash[i] %= mod;
            rhash[n-i-1] = rhash[n-i]+ll(s[n-i-1]-'a'+1)*powm(31, i);
            rhash[i] %= mod;
           // cerr << "hash[" << i << "] = " << hash[i] << endl;
        }
        int sol = 1;
        for(int i=0; 2*i < n-1; ++i) {
            ll newhash = (rhash[i+1]-rhash[2*i+2])*powm(inv(31), n-2*i-2);
            newhash %= mod;
           // cerr << "newhash[" << i << "] = " << newhash << endl;
            if(newhash == hash[i]) {
                sol = max(sol, 2*i+2);
            }
            if(2*i+3 <= n) { 
                ll newhash = (rhash[i+2]-rhash[2*i+3])*powm(inv(31), n-2*i-3);
                newhash %= mod;
                if(newhash == hash[i]) {
                    sol = max(sol, 2*i+3);
                }
            }
        }
        cout << sol << endl;
    }
}
