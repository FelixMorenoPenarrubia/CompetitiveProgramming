#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main() {
    freopen("codecoder.in", "r", stdin);
    freopen("codecoder.out", "w", stdout);
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    vi avec(n);
    vi bvec(n);
    for(int i=0; i < n; ++i) {
        cin >> a[i] >> b[i];
        avec[i] = a[i];
        bvec[i] = b[i];
    }
    sort(avec.begin(), avec.end());
    sort(bvec.begin(), bvec.end());
    map<int, int> amap;
    map<int, int> bmap;
    for(int i=0; i < n; ++i) {
        amap[avec[i]] = i;
        bmap[bvec[i]] = i;
    }
    for(int i=0; i < n; ++i) {
        a[i] = amap[a[i]];
        b[i] = bmap[b[i]];
    }
    vi ra(n);
    vi rb(n);
    for(int i=0; i < n; ++i) {
        ra[a[i]] = i;
        rb[b[i]] = i;
    }
    
    vi ans(n);
    int imax = n-1;
    while(imax > -1) {
        vi cvals;
        int a_p_lv = imax+1;
        int a_lv = imax;
        int b_p_lv = imax+1;
        int b_lv = b[ra[a_lv]];
        
        cvals.push_back(ra[a_lv]);
        
      //  cerr << a_lv << " " << b_lv << endl;
        
        while(a_lv != b_lv) {
            if(b_lv < a_lv) {
                a_p_lv = a_lv;
                for(int v=b_lv; v < b_p_lv; ++v) {
                    a_lv = min(a_lv, a[rb[v]]);
                    cvals.push_back(rb[v]);
                }
            }
            else {
                 b_p_lv = b_lv;
                for(int v=a_lv; v < a_p_lv; ++v) {
                    b_lv = min(b_lv, b[ra[v]]);
                    cvals.push_back(ra[v]);
                }
            }
        }
        for(int i=0; i < (int)cvals.size(); ++i) {
            ans[cvals[i]] = imax;
        }
        imax = a_lv-1;
    }
    for(int i=0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
}
