#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t=0; t < T; ++t) {
        int n;
        cin >> n;
        vvi m(n, vi(n, 0));
        for(int i=0; i < n; ++i) {
            for(int j=0; j < n; ++j) {
                cin >> m[i][j];
            }
        }
        ll trace = 0;
        for(int i=0; i < n; ++i) trace += m[i][i];
        ll rows = 0;
        ll cols = 0;
        vvi a = m;
        for(int i=0; i < n; ++i) {
            vi vis(n+1);
            bool bad = false;
            for(int j=0; j < n; ++j) {
                if(vis[a[i][j]]) bad = true;
                vis[a[i][j]] = 1;
            }
            if(bad) rows++;
        }
        for(int i=0; i < n; ++i) {
            vi vis(n+1);
            bool bad = false;
            for(int j=0; j < n; ++j) {
                if(vis[a[j][i]]) bad = true;
                vis[a[j][i]] = 1;
            }
            if(bad) cols++;
        }
        cout << "Case #" << t << ": " << trace << " " << rows << " " << cols << "\n";
    }
}
