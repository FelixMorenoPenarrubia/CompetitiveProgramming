#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
const ll mod = 1e9+7;

ll n, m;
vvii al;
ll ans;
vi elist;
vi par;
vi p_edg;
vi desc_cnt;
vi dsu;
vi height;

void dfs2(int v, int p) {
    for(int i=0; i < (int)al[v].size(); ++i) {
        int u = al[v][i].first;
        if(u != p) {
            dfs2(u, v);
            ans += al[v][i].second*(desc_cnt[u])*(n-desc_cnt[u]);
            ans %= mod;
        }
    }
}

void dfs(int v, int p) {
    par[v] = p;
    desc_cnt[v] = 1;
    for(int i=0; i < (int)al[v].size(); ++i) {
        int u = al[v][i].first;
        if(u != p) {
            height[u] = height[v]+1;
            dfs(u, v);
            p_edg[u] = elist.size();
            elist.push_back(al[v][i].second);
            desc_cnt[v] += desc_cnt[u];
        }
    }
}

ll findSet(ll x) {
    if(dsu[x] != x) dsu[x] = findSet(dsu[x]);
    return dsu[x];
}
void unionSet(ll x, ll y) {
    dsu[findSet(x)] = findSet(y);
}

int goup(int v) {
    ll prev_w = elist[p_edg[v]];
    ll new_w = ll(floor(sqrt(prev_w)));
    ans += (new_w-prev_w)*desc_cnt[v]*(n-desc_cnt[v]);
    if(ans < 0) ans += mod*((-ans)/mod+1);
    ans %= mod;
    elist[p_edg[v]] = new_w;
    
    if(new_w == 1) {
        unionSet(v, par[v]);
    }
    
    return findSet(par[v]);
}

void query(int u, int v) {
    if(u == v) {
        
    }
    else if(height[u] <= height[v]) {
        query(u, goup(v));
    }
    else {
        query(goup(u), v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    al = vvii(n, vii());
    for(int i=0; i < n-1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        al[u].emplace_back(v, w);
        al[v].emplace_back(u, w);
    }
    par = vi(n, 0);
    elist = vi();
    p_edg = vi(n, 0);
    desc_cnt = vi(n, 0);
    height = vi(n, 0);
    
    dfs(0, -1);
    dfs2(0, -1);
    
    dsu = vi(n);
    for(int i=0; i < n; ++i) dsu[i] = i;
    
    cout << ans << "\n";
    
    for(int z=0; z < m; ++z) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        query(findSet(u), findSet(v));
        cout << ans << "\n";
    }
    
}
