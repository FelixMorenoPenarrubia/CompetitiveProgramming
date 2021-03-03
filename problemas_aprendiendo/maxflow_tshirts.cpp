#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vvi flow;
vvi capacity;
int N;
int inf = 1e9;

int augment(vi& path) {
    queue<int> q;
    q.push(0);
    vi prev = vi(N, -1);
    prev[0] = 0;
    vi minaug = vi(N, inf);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
       // cerr << "BFS on vertex u = " << u << ", parent = " << prev[u] << endl;
        
        for(int v=0; v < N; ++v) {
            if(prev[v] == -1 and (capacity[u][v]-flow[u][v]) > 0) {
                prev[v] = u;
                q.push(v);
                minaug[v] = min(minaug[u], capacity[u][v]-flow[u][v]);
            }
        }
        if(prev[N-1] != -1) break;
    }
    if(prev[N-1] == -1) {
        return 0;
    }
    else {
        int i = N-1;
        while(i != 0) {
            path.push_back(i);
            i = prev[i];
        }
        path.push_back(0);
        return minaug[N-1];
    }
}


int edmonds_karp() {
    vi path;
    int aug = augment(path);
    while (aug > 0) {
        for(int i=1; i < int(path.size()); ++i) {
            int u = path[i];
            int v = path[i-1];
            flow[u][v] += aug;
            flow[v][u] -= aug;
        }
        
        path = vi();
        aug = augment(path);
    }

    int ans = 0;
    for(int i=1; i < N; ++i) {
        ans += flow[0][i];
    }
    return ans;
    
    
}



int main() {
    int T;
    cin >> T;
    for(int caz=0; caz < T; ++caz) {
        int n, m;
        cin >> n >> m;
        N = 1+1+6+m+1;
        map<string, int> tshirts;
        tshirts["XXL"] = 2;
        tshirts["XL"] = 3;
        tshirts["L"] = 4;
        tshirts["M"] = 5;
        tshirts["S"] = 6;
        tshirts["XS"] = 7;
        
        flow = vvi(N, vi(N, 0));
        capacity = vvi(N, vi(N, 0));
        
        capacity[0][1] = n;
        for(int i=2; i <= 7; ++i) {
            capacity[1][i] = n/6;
        }
        for(int i=0; i < m; ++i) {
            string s;
            cin >> s;
            capacity[tshirts[s]][8+i] = 1;
            cin >> s;
            capacity[tshirts[s]][8+i] = 1;
            capacity[8+i][N-1] = 1;
        }
        
        int f = edmonds_karp();
        
       // cerr << f << endl;
        
        cout << ((f == m) ? "YES" : "NO") << endl;
        
    }
}
