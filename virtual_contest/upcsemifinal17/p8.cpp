#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

ll mod = 1e9+9;
vector<string> vs;
vector<set<string> > vl;
vi rec;
int maxsize;

vvi operator * (vvi a, vvi b) {
    int n = a.size();
    vvi r = vvi(n, vi(n, 0));
    for(int i=0; i < n; ++i) {
        for(int j=0; j < n; ++j) {
            for(int k=0; k < n; ++k) {
                r[i][j] += a[i][k] * b[k][j];
                r[i][j] %= mod;
            }
        }
    }
    return r;
}

void print(vvi a) {
    int n = a.size();
    for(int i=0; i < n; ++i) {
        for(int j=0; j < n; ++j) {
            cerr << a[i][j] << " ";
        }
        cerr << endl;
    }
}

void print(vi a) {
    int n = a.size();
    for(int i=0; i < n; ++i) {
        cerr << a[i] << endl;
    }
}

vvi powm(vvi a, int e) {
    if(e == 0) {
        vvi id = vvi(a.size(), vi(a.size(), 0));
        for(int i=0; i < (int) a.size(); ++i) id[i][i] = 1;
        return id;
    }
    vvi s = powm(a, e/2);
    return (e%2) ? (s*s*a) : (s*s);
}


void baq(ll bm, string cs) {
    int m = vs.size();
    for(int i=0; i < m; ++i) {
        //if((bm & (1<<i)) == 0) {
            string ns = cs+vs[i];
            int n = ns.length();
            if(n <= maxsize) {
                if(vl[n].find(ns) == vl[n].end()) {
                    vl[n].insert(ns);
                    baq(bm | (1<<i), ns);
                }
                else {
                    rec[n]--;
                }
            }
       // }
    }
}

void caso(ll l, int m) {
    vs = vector<string>(m);
    for(int i=0; i < m; ++i) cin >> vs[i];
    
    maxsize = 0;
    for(int i=0; i < m; ++i) maxsize += vs[i].length();

    vl = vector<set<string> >(maxsize+1);
    rec = vi(maxsize+1, 0);
    for(int i=0; i < m; ++i) {
        rec[vs[i].length()]++;
    }
    baq(0, "");
    vvi mat = vvi(maxsize, vi(maxsize, 0));
    for(int i=0; i < maxsize; ++i) {
        mat[0][i] = rec[i+1];
    }
    for(int i=1; i < maxsize; ++i) {
        mat[i][i-1] = 1;
    }
    vi vec = vi(maxsize);
    for(int i=0; i < maxsize; ++i) {
        vec[i] = vl[maxsize-i].size();
    }
   
    vvi fmat = powm(mat, l-maxsize);
    ll sol = 0;
    for(int i=0; i < maxsize; ++i) {
        sol += fmat[0][i]*vec[i];
        sol %= mod;
    }
    
    print(mat);
    print(fmat);
    print(vec);
    
     if(l <= maxsize) {
        cout << vec[maxsize-l] << endl;
        return;
    }
    
    cout << sol << endl;
    
}

int main() {
    ll l;
    int m;
    while(cin >> l >> m) caso(l, m);
}
