#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vvi al(n, vi());
    if(2*m >= (n*(n-1))) {
        cout << "NO" << endl;
        return 0;
    }
    vi deg(n, 0);
    for(int i=0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        al[a].push_back(b);
        al[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    int x, y;
    for(int i=0; i < n; ++i) {
        if(deg[i] < n-1) {
            x = i;
            vi vist = vi(n, 0);
            vist[i] = 1;
            for(int j=0; j < deg[i]; ++j) {
                vist[al[i][j]] = 1;
            }
            for(int j=0; j < n; ++j) {
                if(!vist[j]) {
                    y = j;
                    break;
                }
            }
            
            
            break;
        }
    }
    if(y < x) swap(x, y);
    
    //cerr << x << " " << y << endl;
    cout << "YES" << endl;
    for(int i=0; i < n; ++i) {
        if(i <= x) {
            cout << i+1 << " ";
        }
        else if(i < y) {
            cout << i+2 << " ";
        }
        else if(i > y) {
            cout << i+1 << " ";
        }
        else {
            cout << x+2 << " ";
        }
    }
    cout << endl;
    for(int i=0; i < n; ++i) {
        if(i <= x) {
            cout << i+1 << " ";
        }
        else if(i < y) {
            cout << i+2 << " ";
        }
        else if(i > y) {
            cout << i+1 << " ";
        }
        else {
            cout << x+1 << " ";
        }
    }
    cout << endl;
    
    
}
