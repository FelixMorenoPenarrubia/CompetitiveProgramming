#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t=0; t < T; ++t) {
        int n;
        cin >> n;
        string ans = string(n, '-');
        
        vii events;
        for(int i=1; i <= n; ++i) {
            int s, e;
            cin >> s >> e;
            events.emplace_back(s, i);
            events.emplace_back(e, -i);
        }
        sort(events.begin(), events.end());
        int occ1 = 0;
        int occ2 = 0;
        //bool bad = false;
        for(int i=0; i < 2*n; ++i) {
            int src = events[i].second;
            if(src < 0) {
                src = -src;
                if(occ1 == src) {
                    occ1 = 0;
                }
                else if(occ2 == src) {
                    occ2 = 0;
                }
            }
            else {
                if(occ1 == 0) {
                    occ1 = src;
                    ans[src-1] = 'C';
                }
                else if(occ2 == 0) {
                    occ2 = src;
                    ans[src-1] = 'J';
                }
                else {
                    ans = "IMPOSSIBLE";
                    break;
                }
            }
        }
        
        cout << "Case #" << t+1 << ": " << ans << "\n";
    }
}
