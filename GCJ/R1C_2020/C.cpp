#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t=0; t < T; ++t) {
        int n;
        int d;
        cin >> n >> d;
        vi a(n);
        map<ll, int> cnt;
        for(auto &x : a) {
            cin >> x;
            cnt[x]++;
        }
        sort(a.begin(), a.end());
        int ans = d-1;
        for(auto it = cnt.begin(); it != cnt.end(); ++it) {
            ll len = it->first;
            int ccnt = it->second;
            int extracuts = 0;
            for(int j=n-1; j > -1 and ccnt < d; --j) {
                if(a[j] > len) ccnt += a[j]/len;
                else break;
            }
            if(ccnt == d) {
                ans = min(ans, d-it->second);
            }
            
        }
        cout << "Case #" << t+1 << ": " << ans << endl;
        
    }
}





