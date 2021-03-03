#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

int k, p;

int INF = 1e6;
int bfs(int n, vvi & cap, vvi & al, vi & p) {
    queue<ii> q;
    q.push(ii(0, INF)); //0 is source vertex
    int flow = 0;
    p = vi(n, -1);
    p[0] = -2;
    while(!q.empty()) {
        ii cv = q.front();
        q.pop();
        int v = cv.first;
        ll cflow = cv.second;
        if(v == n-1) {
            flow = cflow;
            break; //n-1 is sink vertex;
        }
        for(int i=0; i < al[v].size(); ++i) {
            int u = al[v][i];
            if(cap[v][u] > 0 and p[u] == -1) {
                q.push(ii(u, min(cflow, cap[v][u])));
                p[u] = v;
            }
        }
    }
    return flow;
}

int edmonds_karp(int n, vvi & cap, vvi & al) {
    vi p;
    int flow;
    int mf = 0;
    while(flow = bfs(n, cap, al, p)) {
        int v = n-1;
        mf += flow;
        while(v != 0) {
            int u = p[v];
            cap[v][u] += flow;
            cap[u][v] -= flow;
            v = u;
        }
    }
    return mf;
    
}

void caso() {
    int n = k+p+2;
    vvi orcap = vvi(n, vi(n, 0));
    vvi al = vvi(n, vi());
    int tot = 0;
    for(int i=1; i <= k; ++i) {
        int c;
        cin >> c;
        tot += c;
        orcap[p+i][n-1] = c;
        al[p+i].push_back(n-1);
        al[n-1].push_back(p+i);
    }
    for(int j=1; j <= p; ++j) {
        orcap[0][j] = 1;
        al[0].push_back(j);
        al[j].push_back(0);
        int c;
        cin >> c;
        for(int i=0; i < c; ++i) {
            int x;
            cin >> x;
            orcap[j][p+x] = 1;
            al[j].push_back(p+x);
            al[p+x].push_back(j);
        }
    }
    vvi cap = vvi(orcap);
    if(edmonds_karp(n, cap, al) == tot) {
        cout << "1" << endl;
        for(int i=1; i <= k; ++i) {
            for(int j=1; j <= p; ++j) {
                if(cap[j][p+i] < orcap[j][p+i]) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
        
    }
    else {
        cout << "0" << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> k >> p) {
        if(k == 0 and p == 0) break;
        caso();
    }

}
