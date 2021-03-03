#include<bits/stdc++.h>

using namespace std;


typedef int ll;
typedef vector<ll> vi;

//ll mod = 47;
ll p = 31;
ll invp;
vi powinvdp;
vi powidp;
/*
ll powm(ll b, ll e) {
    if(e == 0) return 1;
    ll sq = powm(b, e/2);
    return ((e&1) ? (((sq*sq)%mod)*b)%mod : (sq*sq)%mod);
}
ll inv(ll a) {
    return powm(a, mod-2);
}
*/
ll powinv(ll e) {
    /*if(e < 0 or e >= powinvdp.size()) {
        vi destroyer = vi(1e9, 0);
    }*/
    
    if(powinvdp[e] == -1) {
        ll sq = powinv(e/2);
        powinvdp[e] = ((e&1) ? (((sq*sq))*invp) : (sq*sq));
    }
    return powinvdp[e];
}





inline void hash_string(const string &s, vi& hash) {
    
    int n = s.length();
    //ll pi = 1;
    hash.push_back(0);
    for(int i=1; i <= n; ++i) {
        ll v = (ll(s[i-1]-'a'+1)*powidp[i-1]+hash[i-1]);
        hash.push_back(v);
        
        //pi = (pi*p)%mod;
    }
    
}

inline ll substr_hash(const vi& hash, int i, int j) {
   /* if(i < 0 or j >= hash.size()-1) {
        vi destroyer = vi(1e9, 0);
    }*/
    return ((((hash[j+1]-hash[i]))*powinv(i)));
}


int main() {
   
    
    string s;
    int maxl = 0;
    vector<string> str;
    while(cin >> s) {
        maxl = max(maxl, (int) s.length());
        str.push_back(s);
        if(s == "*") break;
    }
    int N = str.size();
    
   // invp = inv(p);
    
    invp = 44;
    
    powinvdp = vi(maxl+1, -1);
    powinvdp[0] = 1;
    powinvdp[1] = invp;
    powidp = vi(maxl+1);
    ll pi = 1;
    for(int i=0; i <= maxl; ++i) {
        powidp[i] = pi;
        pi = (pi*p);
    }
    
    for(int t=0; t < N; ++t) {
        s = str[t];
        int n = s.length();
        if(n == 1) {
            cout << 1 << endl;
            continue;
        }
        else if(n == 2) {
            cout << (s[0] == s[1] ? 2 : 1) << endl;
            continue;
        }
        else if(n == 3) {
            if(s[0] == s[2]) cout << 3 << endl;
            else if(s[1] == s[2]) cout << 2 << endl;
            else cout << 1 << endl;
            continue;
        }
        
        vi rhash;
        hash_string(s, rhash);
        reverse(s.begin(), s.end());
        vi hash;
        hash_string(s, hash);
        ll sol = 1;
        for(int i=0; 2*i < n-1; ++i) {
            if(substr_hash(hash, 0, i) == substr_hash(rhash, n-2-2*i, n-2-i)) sol = 2*i+2;
            if(2*i < n-2 and substr_hash(hash, 0, i) == substr_hash(rhash, n-3-2*i, n-3-i)) sol = 2*i+3;
        }
        cout << sol << '\n';
        
        int time = clock();
        
        if((((double) time)/CLOCKS_PER_SEC) > 0.2) {
              vi destroyer = vi(1e9, 0);
            return 0;
        }
    }
}
