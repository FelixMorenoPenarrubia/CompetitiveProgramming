#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;


ll absol(ll x) {
    return x > 0 ? x : -x;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t=0; t < T; ++t) {
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        int m = s.length();
        /*vvi dist(x+2*m, vi(y+2*m, m+1));
        queue<ii> q;
        q.push(ii(m, m));
        dist[m][m] = 0;
        while(!q.empty()) {
            ii p = q.front();
            q.pop();
            int cx = p.first;
            int cy = p.second;
            for(int dx=-1; dx <= 1; ++dx) {
                for(int dy=-1; dy <= 1; ++dy) {
                    if(dx*dy) continue;
                    if(dist[cx+dx][cy+dy] > dist[cx+
                }
            }
        }*/
        int ans = m+1;
        for(int i=0; i < m; ++i) {
            if(s[i] == 'E') x++;
            else if(s[i] == 'W') x--;
            else if(s[i] == 'N') y++;
            else if(s[i] == 'S') y--;
            if(absol(x)+absol(y) <= i+1) {
                ans = i+1;
                break;
            }
        }
        if(ans == m+1) cout << "Case #" << t+1 << ": IMPOSSIBLE" << endl;
        else cout << "Case #" << t+1 << ": " << ans << endl;
        
    }
}





