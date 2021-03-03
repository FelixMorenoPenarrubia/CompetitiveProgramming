#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vi p;
vvi children;
vvii eul_tours;
vi tour_size;
vvi seg_trees;
vi num_leaf;
vi num_desc;
vi min_app;
vi belong_to;

void eul_dfs(int v, int idx, int h) {
    min_app[v] = eul_tours[idx].size();
    belong_to[v] = idx;
    eul_tours[idx].emplace_back(h, v);
    if(children[v].size() == 0) num_leaf[v] = 1;
    num_desc[v] = 1;
    for(int i=0; i < (int)children[v].size(); ++i) {
        eul_dfs(children[v][i], idx, h+1);
        num_leaf[v] += num_leaf[children[v][i]];
        num_desc[v] += num_desc[children[v][i]];
        eul_tours[idx].emplace_back(h, v);
    }
}


void build_st(int idx, int p, int l, int r) {
    if(l == r) {
        seg_trees[idx][p] = l;
    }
    else {
        build_st(idx, 2*p, l, (l+r)/2);
        build_st(idx, 2*p+1, (l+r)/2+1, r);
        int v1 = seg_trees[idx][2*p];
        int v2 = seg_trees[idx][2*p+1];
        seg_trees[idx][p] = eul_tours[idx][v1] < eul_tours[idx][v2] ? v1 : v2;
    }
}

void init_st(int idx) {
    build_st(idx, 1, 0, tour_size[idx]-1);
}

int rmq(int idx, int p, int l, int r, int i, int j) {
    if(r < i or l > j) return -1;
    if(l >= i and r <= j) {
        return seg_trees[idx][p];
    }
    else {
        int v1 = rmq(idx, 2*p, l, (l+r)/2, i, j);
        int v2 = rmq(idx, 2*p+1, (l+r)/2+1, r, i, j);
        if(v1 == -1) return v2;
        if(v2 == -1) return v1;
        return eul_tours[idx][v1] < eul_tours[idx][v2] ? v1 : v2;
    }
}

int lca(int idx, int minapp, int maxapp) {
    return eul_tours[idx][rmq(idx, 1, 0, tour_size[idx]-1, minapp, maxapp)].second;
}

int main() {
    
    freopen("gangsters.in", "r", stdin);
    freopen("gangsters.out", "w", stdout);
    
    int n, q;
    cin >> n >> q;
    p = vi(n);
    children = vvi(n, vi());
    for(int i=1; i < n; ++i) {
        cin >> p[i];
        p[i]--;
        children[p[i]].push_back(i);
    }
    int m = children[0].size();
    eul_tours = vvii(m, vii()); 
    num_leaf = vi(n, 0);
    num_desc = vi(n, 0);
    min_app = vi(n);
    belong_to = vi(n);
    tour_size = vi(m);
    seg_trees = vvi(m);
    
    for(int i=0; i < m; ++i) {
        eul_dfs(children[0][i], i, 0);
        tour_size[i] = eul_tours[i].size();
        seg_trees[i] = vi(4*tour_size[i]);
        init_st(i);
    }
    
    int cans1 = 0;
    int cans2 = 0;
    
    vector<set<int> > apps = vector<set<int> > (m);
    
    for(int cas=0; cas < q; ++cas) {
        char com;
        int v;
        cin >> com >> v;
        --v;
        int idx = belong_to[v];
        if(com == '+') {
            if(apps[idx].size() == 0) {
                cans1++;
                apps[idx].insert(min_app[v]);
            }
            else {
                auto itmax = apps[idx].end();
                itmax--;
                int prev_lc = lca(idx, *(apps[idx].begin()), *itmax);
                int prev_a2 = num_leaf[prev_lc]-apps[idx].size();
                
                apps[idx].insert(min_app[v]);
                
                itmax = apps[idx].end();
                itmax--;
                int act_lc = lca(idx, *(apps[idx].begin()), *itmax);
                int act_a2 = num_leaf[act_lc]-apps[idx].size();
                cans2 += act_a2-prev_a2;
            }
        }
        else {
            if(apps[idx].size() == 1) {
                cans1--;
                apps[idx].erase(apps[idx].find(min_app[v]));
            }
            else {
                auto itmax = apps[idx].end();
                itmax--;
                int prev_lc = lca(idx, *(apps[idx].begin()), *itmax);
                int prev_a2 = num_leaf[prev_lc]-apps[idx].size();
                
                apps[idx].erase(apps[idx].find(min_app[v]));
                
                itmax = apps[idx].end();
                itmax--;
                int act_lc = lca(idx, *(apps[idx].begin()), *itmax);
                int act_a2 = num_leaf[act_lc]-apps[idx].size();
                cans2 += act_a2-prev_a2;
            }
        }
        cout << cans1 << " " << cans2 << endl;
    }
}
