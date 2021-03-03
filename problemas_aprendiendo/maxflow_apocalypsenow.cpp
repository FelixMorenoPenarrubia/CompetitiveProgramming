#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

int n;
int m;
ll INF = 1e12;
ll bfs(vvi & cap, const vvi & al, vi & p) {
    queue<ii> q;
    q.push(ii(0, INF));
    p = vi(m, -1);
    p[0] = -2;
    while(!q.empty()) {
        int v = q.front().first;
        ll cf = q.front().second;
        
        q.pop();
        if(v == m-1) return cf;
        for(int i=0; i < al[v].size(); ++i) {
            if(cap[v][al[v][i]] > 0 and p[al[v][i]] == -1) {
                q.push(ii(al[v][i], min(cf, cap[v][al[v][i]])));
                p[al[v][i]] = v;
            }
        }
    }
    return 0;
}

ll edmonds_karp(vvi & cap, const vvi & al) {
    ll mf = 0;
    vi p(m);
    ll flow;
    while(flow = bfs(cap, al, p)) {
        mf += flow;
        int t = m-1;
        while(t != 0) {
            cap[t][p[t]] += flow;
            cap[p[t]][t] -= flow;
            t = p[t];
        }
    }
    return mf;
}

void caso() {
    vvi am = vvi(n, vi(n, 0));
    for(int i=0; i < n; ++i) 
        for(int j=0; j < n; ++j)
            cin >> am[i][j];
    vvi em = vvi(n, vi(n, 0));
    for(int i=0; i < n; ++i) 
        for(int j=0; j < n; ++j)
            cin >> em[i][j];
    for(int k=0; k < n; ++k) {
        for(int i=0; i < n; ++i) {
            for(int j=i+1; j < n; ++j) {
                am[i][j] = min(am[i][k]+am[k][j], am[i][j]);
                am[j][i] = am[i][j];
            }
        }
    }
    ll totalflow = 0;
    vii el;
    for(int i=0; i < n; ++i) {
        for(int j=i+1; j < n; ++j) {
            if(am[i][j] < 100) {
                el.push_back(ii(i, j));
                totalflow += em[i][j];
            }
        }
    }
    m = 1+n+el.size()+1;
    vvi al = vvi(m, vi());
    vvi orcap = vvi(m, vi(m, 0));
    for(int i=0; i < n; ++i) {
        al[0].push_back(i+1);
        al[i+1].push_back(0);
    }
    for(int k=0; k < el.size(); ++k) {
        int i = el[k].first;
        int j = el[k].second;
        al[n+k+1].push_back(i+1);
        al[n+k+1].push_back(j+1);
        al[n+k+1].push_back(m-1);
        al[i+1].push_back(n+k+1);
        al[j+1].push_back(n+k+1);
        orcap[i+1][n+k+1] = INF;
        orcap[j+1][n+k+1] = INF;
        orcap[n+k+1][m-1] = em[i][j];
    }
    
    vi g(n);
    for(int i=0; i < n; ++i) cin >> g[i];
    
    ll l = 0;
    ll r = INF;
    while(r > l) {
        ll d = (l+r)/2;
        vvi cap = vvi(orcap);
        for(int i=0; i < n; ++i) {
            cap[0][i+1] = g[i]*d;
        }
        ll mf = edmonds_karp(cap, al);
      //  cerr << "d = " << d << " flow = " << mf << endl;
        if(mf == totalflow) {
            r = d;
        }
        else {
            l = d+1; 
        }
    }
    cout << l << endl;
    
    
    
}

int main() {
    while(cin >> n) caso();
}
