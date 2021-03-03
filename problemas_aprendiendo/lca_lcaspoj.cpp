#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


int n;

vi parent;
vvi children;
vii rmqarray;
vi first_appearance;
vi last_appearance;
vvi sparse_table;

void traverse(int v, int h) {
    first_appearance[v] = rmqarray.size();
    rmqarray.emplace_back(h, v);
    for(int i=0; i < int(children[v].size()); ++i) {
        traverse(children[v][i], h+1);
        rmqarray.emplace_back(h, v);
    }
    last_appearance[v] = rmqarray.size()-1;
}

int logarithm(int x) {
    int k = 0;
    while((1<<(k+1)) <= (x)) ++k;
    return k;
}

int rmq(int l, int r) {
    int k = logarithm(r-l+1);
   
    int a = sparse_table[l][k];
    int b = sparse_table[r-(1<<k)+1][k];
    return rmqarray[a] < rmqarray[b] ? a : b;
}

int lca(int u, int v) {
    return rmqarray[rmq(min(first_appearance[u], first_appearance[v]), max(last_appearance[u], last_appearance[v]))].second;
}



int main() {
    int t;
    cin >> t;
    for(int c=0; c < t; ++c) {
        cout << "Case " << c+1  << ":" << endl;
        cin >> n;
        parent = vi(n, -1);
        children = vvi(n, vi());
        rmqarray = vii();
        first_appearance = vi(n, -1);
        last_appearance = vi(n, -1);
        for(int i=0; i < n; ++i) {
            int m;
            cin >> m;
            for(int j=0; j < m; ++j) {
                int s;
                cin >> s;
                --s;
                parent[s] = i;
                children[i].push_back(s);
            }
        }
        for(int i=0; i < n; ++i) {
            if(parent[i] == -1) traverse(i, 0);
        }
        int N = rmqarray.size();
        sparse_table = vvi(N, vi(logarithm(N+1)+1, 0));
        
        for(int i=0; i < N; ++i) {
            sparse_table[i][0] = i;
        }
        for(int k=0; k < logarithm(N)+1; ++k) {
            for(int i=0; i < N; ++i) {
                if(i+(1<<(k+1))-1 < N) {
                    int a = sparse_table[i][k];
                    int b = sparse_table[i+(1<<k)][k];
                    sparse_table[i][k+1] = (rmqarray[a] < rmqarray[b]) ? a : b;
                }
            }
        }
        int q;
        cin >> q;
        for(int i=0; i < q; ++i) {
            int v, u;
            cin >> v >> u;
            --v;
            --u;
            cout << lca(v, u)+1 << endl;
        }
    }
}
