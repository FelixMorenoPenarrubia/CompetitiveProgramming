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
        vi sx = vi(q+1, 0);
        vi sy = vi(q+1, 0);
        int xi, yi;
        xi = yi = 0;
        for(int i=0; i < p; ++i) {
            int x, y;
            char c;
            cin >> x >> y >> c;
            if(c == 'W') {
                sx[x] -= 1;
                ++xi;
            }
            else if(c == 'E') {
                sx[x+1] += 1;
            }
            else if(c == 'S') {
                sy[y] -= 1;
                ++yi;
            }
            else if(c == 'N') {
                sy[y+1] += 1;
            }
        }
        int xans, yans;
        int mx = -1;
        for(int i=0; i <= q; ++i) {
            xi += sx[i];
            if(xi > mx) {
                mx = xi;
                xans = i;
            }
        }
        mx = -1;
        for(int i=0; i <= q; ++i) {
            yi += sy[i];
            if(yi > mx) {
                mx = yi;
                yans = i;
            }
        }
        cout << "Case #" << ts << ": " << xans << " " << yans << endl;
        
    }
}
