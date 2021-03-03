    #include<bits/stdc++.h>
     
    using namespace std;
    typedef long long ll;
    typedef vector<ll> vi;
    typedef vector<vi> vvi;
    typedef pair<ll, ll> ii;
    typedef vector<ii> vii;
    typedef vector<vii> vvii;
     
     
    int n, m, q;
    vii edgelist;
    vi edgeidx;
    vi potential;
    vvii al;
     
    ll INF = 1e15;
     
    void dijkstra(int c) {
        vi dist = vi(n, c);
        dist[0] = 0;
        vvi pq = vvi(c+1, vi());
        pq[0].push_back(0);
        vector<bool> visited = vector<bool>(n, false);
        for(int d=0; d <= c; ++d) {
            for(int t=0; t < int(pq[d].size()); ++t) {
                int v = pq[d][t];
                if(d == dist[v] and not visited[v]) {
                    visited[v] = true;
                    for(int i=0; i < int(al[v].size()); ++i) {
                        int u = al[v][i].second;
                        ll w = al[v][i].first;
                        ll dst = (potential[v]-potential[u])+(w+ll(d));
                        if( dst < dist[u]) {
                            dist[u] = dst;
                           
                           if(dst >= 0 and dst <= ll(c)) pq[dst].push_back(u);
                        }
                    }
                }
            }
        }
      //  cerr << "DIJKSTRA RESULTS" << endl << endl;
        
        for(int i=0; i < n; ++i) {
       //     cerr << i << endl;
         //   cerr << "Increased distance: " << dist[i] << endl;        
            if(potential[i] < INF) potential[i] += dist[i];
    //         cerr << "Resulting distance: " << potential[i] << endl;
        }
    //     cerr << "---" << endl << endl;
    }
     
    /*void construct_graph(vi& l) {
        int l_idx = 0;
        al = vvii(n, vii());
        for(int i=0; i < m; ++i) {
            ll w;
            if(l_idx < int(l.size()) and l[l_idx] == i+1) {
                w = 1;
                ++l_idx;
            }
            else {
                w = 0;
            }
            int a = edgelist[i].first;
            int b = edgelist[i].second;
            al[a].emplace_back(w, b);
            
        }
    }*/
     
    int main() {
      
        cin >> n >> m >> q;
        al = vvii(n, vii());
        potential = vi(n, 0);
        vector<bool> visited = vector<bool>(n, false);
        for(int i=0; i < m; ++i) {
            int a, b;
            ll c;
            cin >> a >> b >> c;
            --a;
            --b;
            edgelist.emplace_back(a, b);
            edgeidx.push_back(al[a].size());
            al[a].emplace_back(c, b);
            
        }
        
        //cerr << "GRAPH READ" << endl;
        
        vi dist (n, INF);
        dist[0] = 0;
        priority_queue<ii, vii, greater<ii> > pq;
        pq.push(ii(0, 0));
        while(!pq.empty()) {
            ll d = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if(d == dist[v] and not visited[v]) {
                visited[v] = true;
                for(int i=0; i < int(al[v].size()); ++i) {
                    int u = al[v][i].second;
                    ll w = al[v][i].first;
                    if(d+w < dist[u]) {
                        dist[u] = d+w;
                        pq.push(ii(d+w, u));
                    }
                }
            }
        }
        for(int i=0; i < n; ++i) {
            potential[i] = dist[i];
        }
        
        //cerr << "DJIKSTRA DONE" << endl;
        
        for(int t=0; t < q; ++t) {
            int quer;
            cin >> quer;
            if(quer == 1) {
                int v;
                cin >> v;
                --v;
                if(potential[v] != INF) cout << potential[v] << endl;
                else cout << -1 << endl;
            }
            else {
                int c;
                cin >> c;
                for(int i=0; i < c; ++i) {
                    int l;
                    cin >> l;
                    --l;
                    int a = edgelist[l].first;
                    al[a][edgeidx[l]].first += 1;
                }
                
                dijkstra(c);
            }
        }
        
    }
