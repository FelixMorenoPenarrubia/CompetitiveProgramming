#include<bits/stdc++.h>

using namespace std;

typedef  int ll;
typedef vector<ll> vi;

ll mod = 17389;

ll powm(ll b, ll e) {
    if(e == 0) return 1;
    ll sq = powm(b, e/2);
    return (e&1) ? (((sq*sq)%mod)*b)%mod : (sq*sq)%mod;
}
ll inv(ll a) {
    return powm(a, mod-2);
}

ll inv31;
int main() {
    string s;
    inv31 = inv(31);
    
    vi destroyer;
    
    while(cin >> s) {
        
        
        
        
        reverse(s.begin(), s.end());
        int n = s.length();
        if(n == 1) {
            cout << 1 << endl;
            continue;
        }
        else if(n == 2) {
            cout << (s[0] == s[1] ? 2 : 1) << endl;
            continue;
        }
       /* if(n > 1e3) {
            destroyer = vi(1e9, 0);
        }*/
        vi hash(n);
        vi rhash(n+1);
        hash[0] = ll(s[0]-'a'+1);
        rhash[n-1] = ll(s[n-1]-'a'+1);
        rhash[n] = 0;
        ll p31 = 31;
        for(int i=1; i < n; ++i) {
            hash[i] = hash[i-1]+ll(s[i]-'a'+1)*p31;
            hash[i] %= mod;
            rhash[n-i-1] = rhash[n-i]+ll(s[n-i-1]-'a'+1)*p31;
            rhash[n-i-1] %= mod;
            p31 *= 31;
            p31 %= mod;
            
            
         //   cerr << "hash[" << i << "] = " << hash[i] << endl;
          //  cerr << "rhash[" << n-i-1 << "] = " << rhash[n-i-1] << endl;
        }
        int sol = 1;
        ll pi31 = powm(inv31, n-2);
        for(int i=0; 2*i < n-1; ++i) {
            ll newhash = (rhash[i+1]-rhash[2*i+2]+mod)*pi31;
            newhash %= mod;
            
            
          //  cerr << "newhash[" << i << "] = " << newhash << endl;
            
            
            if(newhash == hash[i]) {
                sol = max(sol, 2*i+2);
            }
            pi31 *= 31;
            pi31 %= mod;
            if(2*i+3 <= n) { 
                 newhash = (rhash[i+2]-rhash[2*i+3]+mod)*pi31;
                newhash %= mod;
                
           //      cerr << "newhash[" << i << "] = " << newhash << endl;
                
                if(newhash == hash[i]) {
                    sol = max(sol, 2*i+3);
                }
            }
            pi31 *= 31;
            pi31 %= mod;
        }
        cout << sol << endl;
    }
}
