#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define X first
#define Y second

vvi al;

ll rec(int v, int p) {
    //cerr << "rec(" << v << ", " << p << ")" << endl;
    
    int sc = 1;
    for(int i=0; i < (int)al[v].size(); ++i) {
        int j = al[v][i];
        if(j == p) continue;
        int s = rec(j, v);
        if(s == -1) return -1;
        sc += s;
    }
    if(sc > 8) return -1;
    if(sc == 8) return 0;
    return sc;
}

int main() {
    int n;
    while(cin >> n) {
        n *= 8;
        al = vvi(n, vi());
        for(int i=0; i < n-1; ++i) {
            int x, y;
            cin >> x >> y;
            al[x].push_back(y);
            al[y].push_back(x);
        }
        cout << ((rec(0, -1) == 0) ? "yes" : "no") << endl;
    }
}
