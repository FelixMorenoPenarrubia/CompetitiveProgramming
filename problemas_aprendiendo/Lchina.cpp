#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;


const ll INF = 1e12;

vi stmin;
vi stcount;
vi stlazy;


void build(int p, int l, int r) {
    if(l == r) {
        stmin[p] = 0;
        stcount[p] = 1;
    }
    else {
        build(2*p, l, (l+r)/2);
        build(2*p+1, (l+r)/2+1, r);
        
        stmin[p] = min(stmin[2*p], stmin[2*p+1]);
        stcount[p] = 0;
        if(stmin[2*p] == stmin[p]) stcount[p] += stcount[2*p];
        if(stmin[2*p+1] == stmin[p]) stcount[p] += stcount[2*p+1];
        
    }
}

void propagate(int p) {
    if(2*p+1 < (int)stmin.size()) {
        stmin[2*p] += stlazy[p];
        stlazy[2*p] += stlazy[p];
        stmin[2*p+1] += stlazy[p];
        stlazy[2*p+1] += stlazy[p];
    }
    stlazy[p] = 0;
}

void update(int p, int l, int r, int i, int j, ll v) {
    
    if(i > r or j < l) return;
    propagate(p);
    if(l >= i and r <= j) {
        stmin[p] += v;
        stlazy[p] += v;
    }
    else {
        update(2*p, l, (l+r)/2, i, j, v);
        update(2*p+1, (l+r)/2+1, r, i, j, v);
        
        stmin[p] = min(stmin[2*p], stmin[2*p+1]);
        stcount[p] = 0;
        if(stmin[2*p] == stmin[p]) stcount[p] += stcount[2*p];
        if(stmin[2*p+1] == stmin[p]) stcount[p] += stcount[2*p+1];
        
    }
}  

ii rmq(int p, int l, int r, int i, int j) {
    
    
    
    
    if(i > r or j < l) return ii(INF, 0);
    propagate(p);
    if(l >= i and r <= j) {
        return ii(stmin[p], stcount[p]);
    }
    
        ii info1 = rmq(2*p, l, (l+r)/2, i, j);
        ii info2 = rmq(2*p+1, (l+r)/2+1, r, i, j);
        
        ii info;
        info.first = min(info1.first, info2.first);
        info.second = 0;
        if(info1.first == info.first) info.second += info1.second;
        if(info2.first == info.first) info.second += info2.second;
        
       // cerr << "rmq(" << p<< ", " << l << ", " << r << ", " << i << ", " << j << ")" << endl;
       // cerr << "info = " << info.first << " " << info.second << endl;
        
        return info;
    
}  


void init_st(int n) {
    stmin = vi(4*n);
    stcount = vi(4*n);
    stlazy = vi(4*n,0);
    build(1,0, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for(int cas=0; cas < T; ++cas) {
        int n; 
        cin >> n;
        vi a (n);
        for(int i=0; i < n; ++i) {
            cin >> a[i];
        }
        
        ll sol = 0;
        
        init_st(n);
        
        vii max_stack;
        vii min_stack;
        max_stack.push_back(ii(INF, -1));
        min_stack.push_back(ii(-INF, -1));
        map<ll,ll> last_app;
        
        for(int i=0; i < n; ++i) {
            
            ll cval = a[i];
            ll cindex = i;
            while(cval >= max_stack.back().first) {
                ll oval = max_stack.back().first;
                ll oindex = max_stack.back().second;
                max_stack.pop_back();
                update(1, 0, n, oindex, cindex-1, cval-oval);
                cindex = oindex;
            }
            max_stack.push_back(ii(cval, cindex));
            
            cindex = i;
            while(cval <= min_stack.back().first) {
                ll oval = min_stack.back().first;
                ll oindex = min_stack.back().second;
                min_stack.pop_back();
                update(1, 0, n, oindex, cindex-1, -(cval-oval));
                cindex = oindex;
            }
            min_stack.push_back(ii(cval, cindex));
            
            if(last_app.find(cval) == last_app.end()) {
                last_app[cval] = -1;
            }
            update(1, 0, n, last_app[cval]+1, i, -1);
            
            last_app[cval] = i;
            
          //  cerr << "i = " << i << endl;
            
            
            ii info = rmq(1, 0, n, 0, i);
            if(info.first == -1) sol += info.second;
            
         //   cerr << "infodef = " << info.first << " " << info.second << endl;
            
            
         /*   cerr << " Current ST state: " << endl;
            
            for(int j=0; j <= i; ++j) {
                cerr << rmq(1, 0, n, j, j).first << " ";
            }
            cerr << endl;*/
            
        }
        
        cout << "Case #" << cas+1 << ": " << sol << '\n';
    }
}
