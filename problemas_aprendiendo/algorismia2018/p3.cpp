#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;





int main() {
    int n;
    while(cin >> n) {
        vi v(3*n);
        for(int i=0; i < 3*n; ++i) cin >> v[i];
        sort(v.begin(), v.end());
        ll ans = 0;
        for(int i=0; i < n; ++i) ans += v[3*i+1]+v[3*i+2];
        cout << ans << endl;
    }
}
