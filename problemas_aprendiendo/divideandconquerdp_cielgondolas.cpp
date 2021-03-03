#include<bits/stdc++.h>

using namespace std;

typedef  int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
vi dp;
vi ndp;
vvi s;

void compute_cost( int l, int r, int optl, int optr) {
    if(l > r) return;
    
   // cerr << "compute_cost(" << i << ", " << l << ", " << r << ", " << optl << ", " << optr << ")" << endl;
    
    int mid = (l+r)/2;
    int opt = -1;
    ll mv = 1e9;
    for(int j=optl; j <= min(optr, mid); ++j) {
        ll v = dp[j] + s[mid][mid]-s[j][mid]-s[mid][j]+s[j][j];
        
        //cerr << "j = " << j << " v = " << v << endl;
        
        if(mv > v) {
            mv = v;
            opt = j;
        }
    }
    
    ndp[mid] = mv;
    
    //cerr << "dp[" << i << "][" << mid << "] = " << mv << endl;
    
    compute_cost( l, mid-1, optl, opt);
    compute_cost( mid+1, r, opt, optr);
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
   // scanf("%d", &n);
    //scanf("%d", &k);
  //  vvi u = vvi(n, vi(n, 0));
    s = vvi(n+1, vi(n+1, 0));
    for(int i=0; i < n; ++i) {
        for(int j=0; j < n; ++j) {
            ll u;
            cin >> u;
           // scanf("%d", &u);
            s[i+1][j+1] = u+s[i+1][j]+s[i][j+1]-s[i][j];
        }
    }
  //  if(n > 3900) {printf("basura"); return 0;}
    
   /* for(int i=1; i <= n; ++i) {
        for(int j=1; j <= n; ++j) {
            s[i][j] = u[i-1][j-1]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }*/
    dp = vi(n+1, 0);
    ndp = vi(n+1, 0);
    for(int i=1; i <= n; ++i) dp[i] = 1e9;
    for(int i=1; i <= k; ++i) {
        compute_cost(0, n, 0, n);
        dp = ndp;
    }
    //printf("%d\n", dp[n]/2);
    cout << dp[n]/2;
}
