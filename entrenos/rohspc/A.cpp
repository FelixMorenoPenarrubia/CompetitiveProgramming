#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vvi empl(n);
    ll maxs = 0;
    for(int i=0; i < n; ++i) {
        int m;
        cin >> m;
        for(int j=0; j < m; ++j) {
            ll x;
            cin >> x;
            empl[i].push_back(x);
            maxs = max(maxs, x);
        }
    }
    ll ans = 0;
    for(int i=0; i < n; ++i) {
        ll m = empl[i].size();
       // ll sum = 0;
        ll cmaxs = 0;
        for(int j=0; j < m; ++j) {
         //   sum += empl[i][j];
            cmaxs = max(empl[i][j], cmaxs);
        }
        ans += m*(maxs-cmaxs);
    }
    cout << ans << endl;
}
