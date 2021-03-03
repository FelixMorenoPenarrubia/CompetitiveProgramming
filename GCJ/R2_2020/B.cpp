#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int INF = 1e6;

int n, m;
vvi al;
vii el;
vi dist;
vi par;

void assign_parent(int v, int d) {
    for(int i=0; i < (int)al[v].size(); ++i) {
        int u = al[v][i];
        if(dist[u] < d) {
            par[v] = u;
            break;
        }
    }
    dist[v] = d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t=0; t < T; ++t) {
        cin >> n >> m;
        vi w(n-1);
        for(auto &x : w) cin >> x;
         al = vvi(n, vi());
         el = vii();
        for(int i=0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            al[u].push_back(v);
            al[v].push_back(u);
            el.emplace_back(u, v);
        }
        
        dist = vi(n, INF);
        dist[0] = 0;
         par = vi(n, -1);
        vvi aft(n+1);
        vii vec;
        for(int i=0; i < n-1; ++i) {
            if(w[i] > 0) {
                vec.emplace_back(w[i], i+1);
            }
            else {
                aft[-w[i]].push_back(i+1);
            }
        }
        
        sort(vec.begin(), vec.end());
        int idx = 1;
        int vec_idx = 0;
        int cur_dist = 0;
        while(idx < n) {
            if(aft[idx].size() > 0) {
                for(int j=0; j < (int)aft[idx].size(); ++j) {
                    assign_parent(aft[idx][j], cur_dist+1);
                }
                idx += aft[idx].size();
                cur_dist++;
            }
            else {
                int v = vec[vec_idx].second;
                cur_dist = vec[vec_idx].first;
                assign_parent(v, cur_dist);
                idx++;
                vec_idx++;
            }
        }
        vi ans(m);
        for(int i=0; i < m; ++i) {
            int v = el[i].first;
            int u = el[i].second;
            if(par[v] == u) {
                ans[i] = dist[v]-dist[u];
            }
            else if(par[u] == v) {
                ans[i] = dist[u]-dist[v];
            }
            else {
                ans[i] = INF;
            }
        }
        cout << "Case #" << t+1 << ": ";
        for(int i=0; i < m; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
