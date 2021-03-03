#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define X first
#define Y second

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
ll key(ii a) {
    return (a.X << 20) | a.Y;
}


int main() {
    int n;
    while(cin >> n) {
        vii points (n);
        for(int i=0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            points[i] = ii(x, y);
        }
        if(n <= 2) {
            cout << "2  " << points[0].X << " " << points[0].Y << "  " << points[1].X << " " << points[1].Y << endl;
        }
        else {
            int cp;
            ii gslope;
            while(true) {
                cp = rand()%n;
                int y = points[cp].Y;
                int x = points[cp].X;
                
                map<ii, int> slope;
                bool good = false;
                for(int i=0; i < n; ++i) {
                    if(i == cp) continue;
                    ii m = ii(points[i].Y-y, points[i].X-x);
                    int d = gcd(m.X, m.Y);
                    if(d == 0) {
                       if(m.X == 0) {
                          m.Y = 1;
                       }
                       else {
                          m.X = 1;
                       }
                    }
                    else {
                        m.X /= d;
                        m.Y /= d;
                    }
                    
                    slope[m]++;
                    if(5*(slope[m]+1) >= n) {
                        good = true;
                        gslope = m;
                        break;
                    }
                }
                if(good) break;
            }
            int y = points[cp].Y;
            int x = points[cp].X;
            vii linepoints;
            for(int i=0; i < n; ++i) {
                    ii m = ii(points[i].Y-y, points[i].X-x);
                    int d = gcd(m.X, m.Y);
                    if(d == 0) {
                       if(m.X == 0) {
                          m.Y = 1;
                       }
                       else {
                          m.X = 1;
                       }
                    }
                    else {
                        m.X /= d;
                        m.Y /= d;
                    }
                    
                    if(m == gslope or i == cp) {
                        linepoints.push_back(points[i]);
                    }
            }
            int ans = linepoints.size();
            cout << ans << "  ";
            for(int i=0; i < ans; ++i) {
                cout << linepoints[i].X << " " << linepoints[i].Y;
                cout << ((i == ans-1) ? "\n" : "  ");
            }
        }
    }
}
