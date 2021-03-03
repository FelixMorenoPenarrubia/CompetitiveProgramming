#include<bits/stdc++.h>

using namespace std;

typedef  int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define X first
#define Y second


int main() {
    int n;
    while(cin >> n) {
        vi a (n);
        for(int i=0; i < n; ++i) cin >> a[i];
        ll sum = 0;
        for(int i=0; i < n; ++i) sum += a[i];
        vi pa (n);
        for(int i=0; i < n; ++i) {
            int j;
            cin >> j;
            --j;
            pa[j] = a[i];
        }
        vi dp = vi(n/2+1, 0);
        for(int i=0; i < n; ++i) {
            int pdp = dp[0];
            dp[0] = dp[0]+pa[i];
            for(int j=1; j < i/2+1; ++j) {
                int npdp = dp[j];
                dp[j] = min(dp[j]+pa[i], pdp);
                pdp = npdp;
            }
            if(i%2 == 0) {
                dp[i/2+1] = pdp;
            }
            else {
                dp[i/2+1] = min(dp[i/2+1]+pa[i], pdp);
            }
        }
        cout << sum-dp[n/2] << endl;
        
    }
}
