#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int ts=0; ts<t; ++ts) {
        int p, q;
        cin >> p >> q;
        int minx, miny;
        int n, s, w, e;
        n = s = w = e = 0;
        minx = miny = 0;
        for(int i=0; i < p; ++i) {
           int x, y;
           char c;
           cin >> x >> y >> c;
           if(c == 'N') {
               ++n;
               miny = max(miny, y+1);
           }
           else if(c == 'S') {
               ++s;
           }
           else if(c == 'W') {
               ++w;
           }
           else if(c == 'E') {
               ++e;
               minx = max(minx, x+1);
           }
        }
        int ans = max(s+w, max(n+w, max(s+e, n+e)));
        cout << "Case #" << ts+1 << ": ";
        if(ans == s+w) {
            cout << "0 0" << endl;
        }
        else if(ans == n+w) {
            cout << "0 " << miny << endl;
        }
        else if(ans == s+e) {
            cout << minx << " 0" << endl;
        }
        else {
            cout << minx << " " << miny << endl;
        }
        
    }
}
