#include<bits/stdc++.h>

using namespace std;

typedef  int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef long double ld;
typedef pair<ld, ld> dd;

#define X first
#define Y second

ld INF = 1e2;

dd solve_eq(ld a, ld b, ld c) {
    if(a == 0) {
        if(b == 0) {
            return dd(INF, INF);
        }
        else {
            ld fs = (-c)/b;
            ld ss = (-c)/b;
            if(fs > ss) swap(fs, ss);
                
            if(fs >= 0) return dd(fs, ss);
            else if(ss >= 0) return dd(ss, INF);
            else return dd(INF, INF);
        }
    }
    else {
        ld delta = b*b-4*a*c;
        if(delta < 0) {
            return dd(INF, INF);
        }
        else {
            ld sqd = sqrt(delta);
            ld fs = (-b+sqd)/(2*a);
            ld ss = (-b-sqd)/(2*a);
            if(fs > ss) swap(fs, ss);
            
            if(fs >= 0) return dd(fs, ss);
            else if(ss >= 0) return dd(ss, INF);
            else return dd(INF, INF);
        }
    }
}

bool isbad(dd a) {
    return (a == dd(INF, INF));
}

int main() {
    ld l1, l2, d, v1, a1, v2, a2;
    cout.setf(ios::fixed);
    cout.precision(4);
    while(cin >> l1 >> l2 >> d >> v1 >> a1 >> v2 >> a2) {
        ld xf1 = 0;
        ld xl1 = l1;
        ld xf2 = l1+d;
        ld xl2 = l1+d+l2;
        dd l1f2 = solve_eq(0.5*(a1-a2), v1-v2, xl1-xf2);
        if(isbad(l1f2)) {
            
         //   cerr << "#1" << endl;
            
            cout << 0.0 << endl;
        }
        else {
            dd f1l2 = solve_eq(0.5*(a1-a2), v1-v2, xf1-xl2);
            if(isbad(f1l2)) {
                
              //  cerr << "#2" << endl;
                
                cout << l1f2.Y-l1f2.X << endl;
            }
            else if(a1 < a2) {
                
               // cerr << "#3" << endl;
                
                cout << (f1l2.X-l1f2.X)+(l1f2.Y-f1l2.Y) << endl;
            }
            else {
                
                //cerr << "#4" << endl;
                
                cout << f1l2.X - l1f2.X << endl;
            }
            
        }
    }
}
