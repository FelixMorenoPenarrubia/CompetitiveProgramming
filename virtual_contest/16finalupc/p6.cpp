#include<bits/stdc++.h>

using namespace std;

typedef  int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define X first
#define Y second

vi st;
vi lazy;


void build_st(int p, int l, int r) {
    if(l == r) {
        st[p] = l/2+1;
    }
    else {
        build_st(2*p, l, (l+r)/2);
        build_st(2*p+1, (l+r)/2+1, r);
        st[p] = min(st[2*p], st[2*p+1]);
    }
}

void propagate(int p, int l, int r) {
    if(l == r) {
        st[p] += lazy[p];
        lazy[p] = 0;
    }
    else {
        st[p] += lazy[p];
        lazy[2*p] += lazy[p];
        lazy[2*p+1] += lazy[p];
        lazy[p] = 0;
    }
}
int INF = 1e6;
void update(int p, int l, int r, int i, int j, int v) {
    propagate(p, l, r);
    if(l > j or r < i) return;
    
    if(l >= i and r <= j) {
        lazy[p] += v;
        propagate(p, l, r);
    }
    else {
        
        update(2*p, l, (l+r)/2, i, j, v);
        update(2*p+1, (l+r)/2+1, r, i, j, v);
        st[p] = min(st[2*p], st[2*p+1]);
       
    }
}

int rmq(int p, int l, int r, int i, int j) {
   
    if(l > j or r < i) return INF;
    propagate(p, l, r);
    if(l >= i and r <= j) {
        return st[p];
    }
    else {
        int p1 = rmq(2*p, l, (l+r)/2, i, j);
        int p2 = rmq(2*p+1, (l+r)/2+1, r, i, j);
        return min(p1, p2);
    }
}



int main() {
    int n;
    while(cin >> n) {
        vi a (n);
        for(int i=0; i < n; ++i) cin >> a[i];
        //ll sum = 0;
        //for(int i=0; i < n; ++i) sum += a[i];
    //    vi pa (n);
        vi p(n);
        for(int i=0; i < n; ++i) {
            int j;
            cin >> j;
            --j;
          //  pa[j] = i;
            p[i] = j;
        }
        
        vii sa;
        
        /*
        
        vvi idx = vvi(1e5+1, vi());
        for(int i=0; i < n; ++i) {
            idx[a[i]].push_back(i);
        }
        for(int i=0; i <= 1e5; ++i) {
            for(int j=0; j < idx[i].size(); ++j) {
                sa.push_back(ii(i, idx[i][j]));
            }
        }
        
        */
        
         for(int i=0; i < n; ++i) sa.push_back(ii(a[i], i));
        sort(sa.begin(), sa.end());
        
        
        st = vi(4*n, 0);
        lazy = vi(4*n, 0);
        build_st(1, 0, n-1);
        
        ll sum = 0;
        int cnt = 0;
        for(int i=0; i < n; ++i) {
            int j = sa[n-i-1].second;
            //cerr << sa[n-i-1].first << endl;
            //cerr << "rmq( " << p[j] << ") = " << rmq(1, 0, n-1, p[j], n-1) << endl;
            
            if(rmq(1, 0, n-1, p[j], n-1) > 0) {
                sum += sa[n-i-1].first;
                update(1, 0, n-1, p[j], n-1, -1);
                ++cnt;
                if(cnt == n/2) break;
            }
        }
        cout << sum << '\n';
    }
}
