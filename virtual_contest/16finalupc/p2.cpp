#include<bits/stdc++.h>

using namespace std;

typedef  int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define X first
#define Y second

vvi al;
vii bridges;
vi depth;
int dfs(int v, int d, int p) {
    //cerr << "rec(" << v << ", " << p << ")" << endl;
    
    depth[v] = d;
    int mind = d;
    for(int i=0; i < (int)al[v].size(); ++i) {
        int j = al[v][i];
        if(j == p) continue;
        if(depth[j] >= 0) {
            mind = min(mind, depth[j]);
        }
        else {
            mind = min(mind, dfs(j, d+1, v));
        }
    }
    if(d > 0 and mind == d) {
        bridges.push_back(ii(min(v, p), max(v, p)));
    }
    return mind;
   
}

int main() {
    int n, m;
    while(cin >> n >> m) {
    
        al = vvi(n, vi());
        bridges = vii();
        depth = vi(n, -1);
        for(int i=0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            al[x].push_back(y);
            al[y].push_back(x);
        }
        for(int i=0; i < n; ++i) {
            if(depth[i] == -1) dfs(i, 0, -1);
        }
        sort(bridges.begin(), bridges.end());
        int ans = bridges.size();
        cout << ans << endl;
        for(int i=0; i < ans; ++i) {
            cout << bridges[i].X << " " << bridges[i].Y;
            cout << ((i == ans-1) ? "\n" : "  ");
        }
        if(ans == 0) cout << endl;
        cout << "----------" << endl;
    }
}
