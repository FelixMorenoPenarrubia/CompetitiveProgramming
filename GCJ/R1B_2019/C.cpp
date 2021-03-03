#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int absol(int x) {
    return x > 0 ? x : -x;
}
int n, thek;
vi c;
vi d;
vvi mc;
vvi md;
/*
int maxc(int a, int b) {
    return c[a] > c[b] ? a : b;
}
int maxd(int a, int b) {
    return d[a] > d[b] ? a : b;
}

int rmqc(int l, int r) {
     while((1<<k) <= (r-l+1)) ++k;
    --k;
    return maxc(mc[l][k], mc[r-(1<<k)+1][k]);
}
int rmqd(int l, int r) {
     while((1<<k) <= (r-l+1)) ++k;
    --k;
    return maxd(md[l][k], md[r-(1<<k)+1][k]);
}*/



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int ts=0; ts < t; ++ts) {
        
        cin >> n >> thek;
        c =vi(n);
        d =vi(n);
        for(int i=0; i < n; ++i) cin >> c[i];
        for(int i=0; i < n; ++i) cin >> d[i];
        int lgn = 0;
        while((1<<lgn) <= n) lgn++;
        vvi mc = vvi(n,vi(lgn+1, 0));
        vvi md = vvi(n,vi(lgn+1, 0));
        
       // cerr << "Hi1" << endl;
        
        for(int i=0; i < n; ++i) {
            mc[i][0] = c[i];
            md[i][0] = d[i];
        }
        for(int i=1; i <= lgn; ++i) {
           // cerr << "Hi " << i << endl;
            for(int j=0; j < n; ++j) {
                if(j + (1<<(i-1)) < n) {
                    mc[j][i] = max(mc[j][i-1], mc[j+(1<<(i-1))][i-1]);
                    md[j][i] = max(md[j][i-1], md[j+(1<<(i-1))][i-1]);
                }
            }
        }
        ll sol = 0;
        for(int l=0; l < n; ++l) {
            for(int r=l; r < n; ++r) {
                int k = 1;
                while((1 << k) <= (r-l+1)) ++k;
                --k;
                int maxc = max(mc[l][k], mc[r-(1<<k)+1][k]);
                int maxd = max(md[l][k], md[r-(1<<k)+1][k]);
                if(absol(maxc-maxd) <= thek) ++sol;
            }
        }
        cout << "Case #" << ts+1 << ": " << sol << endl;
    }
}
