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
}
ll sol(int l, int r) {
  if(l > r) return 0;
    if(r ==l) {
        if(absol(c[l]-d[l]) <= k) return 1;
        return 0;
    }
    int mci = rmqc(l, r);
    int mdi = rmqd(l, r);
    int mi = c[mci] > d[mdi] ? mci : mdi;
    ll csol = 0;
    if(mi == mci) {
        //der
      int der;
      {
            int low = mi;
            int upp = r+1;
            while(upp > low) {
               int mid = (upp+low)/2;
               int maxd = d[rmqd(mi, mid)];
               if(c[mi]-maxd <= k) {
                 upp = mid;
               }
               else low = mid+1;
            }
            der = low;
      }
      int izq;
      {
            int low = l-1;
            int upp = mi;
            while(upp > low) {
               int mid = (upp+low)/2;
               int maxd = d[rmqd(mi, mid)];
               if(c[mi]-maxd > k) {
                 upp = mid-1;
               }
               else low = mid;
            }
            izq = low;
      }
      csol = izq+1 + r-der+1;
      
    }
    else {
      int der;
      {
            int low = mi;
            int upp = r+1;
            while(upp > low) {
               int mid = (upp+low)/2;
               int maxd = c[rmqc(mi, mid)];
               if(d[mi]-maxd <= k) {
                 upp = mid;
               }
               else low = mid+1;
            }
            der = low;
      }
      int izq;
      {
            int low = l-1;
            int upp = mi;
            while(upp > low) {
               int mid = (upp+low)/2;
               int maxd = c[rmqc(mi, mid)];
               if(d[mi]-maxd > k) {
                 upp = mid-1;
               }
               else low = mid;
            }
            izq = low;
      }
      csol = izq+1 + r-der+1;
    }
    return csol + sol(l, mi-1)+ sol(mi+1, r);
}


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
        
        //cerr << "Hi1" << endl;
        
        for(int i=0; i < n; ++i) {
            mc[i][0] = i;
            md[i][0] = i;
        }
        for(int i=1; i <= lgn; ++i) {
          //  cerr << "Hi " << i << endl;
            for(int j=0; j < n; ++j) {
                if(j + (1<<(i-1)) < n) {
                    mc[j][i] = maxc(mc[j][i-1], mc[j+(1<<(i-1))][i-1]);
                    md[j][i] = maxd(md[j][i-1], md[j+(1<<(i-1))][i-1]);
                }
            }
        }
        ll sol = 0;
        for(int r=0; r < n; ++r) {
            
           // cerr << "Ho " << r << endl;
            
            
            sol += r-low+1;
        }
        cout << "Case #" << ts+1 << ": " << sol << endl;
    }
}
