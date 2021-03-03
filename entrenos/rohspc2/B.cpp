#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;


ld K= 1.3492;

struct point {
    ld x, y;
    point() {
        
    }
    point(ld _x, ld _y) {
        x = _x;
        y = _y;
    }
};

point operator-(point a, point b) {
    return point(a.x-b.x, a.y-b.y);
}

ld operator^(point a, point b) {
    return a.x*b.y-a.y*b.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        point a1;
        point a2;
        point b1;
        point b2;
        point v;
        cin >> a1.x >> a1.y  >> a2.x >> a2.y >> b1.x >> b1.y >> b2.x >> b2.y >> v.x >> v.y;
        
        a1.x = K*a1.x+a1.y;
        a2.x = K*a2.x+a2.y;
        b1.x = K*b1.x+b1.y;
        b2.x = K*b2.x+b2.y;
        v.x =  K*v.x+v.y;
        
        a2 =  a2-a1;
        b1 = b1-a1;
        b2 = b2-a1;
        
        ld det = v.x*a2.y-v.y*a2.x;
        if(det == 0) {
            b1.y -= b1.x * (v.y/v.x);
            b2.y -= b2.x * (v.y/v.x);
            if(b1.y < 0) {
                if(b2.y < 0) {
                    cout << "No" << endl;
                }
                else {
                    ld xc = ((b2.y*b2.x)-(b1.y*b1.x))/(b2.y-b1.y);
                    if(xc*v.x >= 0) {
                        cout << "Yes" << endl;
                    }
                    else {
                        cout << "No" << endl;
                    }
                }
            }
            else if(b2.y < 0) {
                ld xc = ((b1.y*b1.x)-(b2.y*b2.x))/(b1.y-b2.y);
                    if(xc*v.x >= 0) {
                        cout << "Yes" << endl;
                    }
                    else {
                        cout << "No" << endl;
                    }
            }
            else {
                cout << "No" << endl;
            }
            continue;
        }
        ld a = -(v.y)/det;
        ld b = v.x/det;
        ld c = a2.y/det;
        ld d = (-a2.x)/det;
        v = point(a*v.x+b*v.y, c*v.x+d*v.y);
        a2 = point(a*a2.x+b*a2.y, c*a2.x+d*a2.y);
        
       // cerr << a2.x << " " << a2.y << " " << v.x << " " << v.y << endl;
        
        b1 = point(a*b1.x+b*b1.y, c*b1.x+d*b1.y);
        b2 = point(a*b2.x+b*b2.y, c*b2.x+d*b2.y);
        
        if(b1.y < 0) {
            if(b2.y < 0) {
                cout << "No" << endl;
                continue;
            }
            else {
                b1 = point((-b1.y*b1.x+b2.y*b2.x)/(b2.y-b1.y), 0);
            }
        }
        else if(b2.y < 0) {
            b2 = point((-b2.y*b2.x+b1.y*b1.x)/(b1.y-b2.y), 0);
        }
        if(b1.x > b2.x) swap(b1, b2);
        if(b2.x < 0 or b1.x > 1) {
            cout << "No" << endl;
        }
        else cout << "Yes" << endl;
        
    }
}
