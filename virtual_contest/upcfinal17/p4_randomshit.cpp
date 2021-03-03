#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef  long double ld;
typedef vector<ld> vld;
typedef pair<ld, ld> dd;
typedef vector<dd> vdd;

ld EPS = 1e-12;
ld PI = 2*acos(0.0);
ld sq(ld x) {
    return x*x;
}

ld sign(ld x) {
    return (x > 0) ? 1 : -1;
}
bool has_positive_solution(ld a, ld b, ld c) {
    if(sq(b) < 4*a*c) return false;
    ld delta = sqrt(sq(b)-4*a*c);
    ld sol1 = (-b+delta)*sign(a);
    ld sol2 = (-b-delta)*sign(a);
    return (sol1 >= 0 or sol2 >= 0);
}

bool caso(ld p, int n) {
    vld x(n);
    vld y(n);
    vld r(n);
    vld s(n);
    for(int i=0; i < n; ++i) cin >> x[i] >> y[i] >> r[i] >> s[i];
   
    vdd angles;
    ld mincover = 0;
    ld maxcover = 2*PI;
    for(int i=0; i < n; ++i) {
        ld d = sqrt(sq(x[i])+sq(y[i]));
        ld low = 0;
        ld upp = PI;
        while(upp-low > EPS) {
            ld mid = (upp+low)/2;
            ld a = (sq(p)-sq(s[i]));
            ld b = -2*(d*p*cos(mid)+r[i]*s[i]);
            ld c = sq(d)-sq(r[i]);
            if(has_positive_solution(a, b, c)) {
                low = mid;
            }
            else {
                upp = mid;
            }
        }
        ld alpha = low;
        ld beta = atan2(y[i], x[i]);
        if(y[i] < 0) beta += 2*PI;
        angles.push_back(dd(beta-alpha, beta+alpha));
        if(beta-alpha < 0) {
            if(beta + alpha > 0) {
                maxcover = min(maxcover, 2*PI + beta-alpha);
            }
            else {
                while(1) {
                    
                }
            }
        }
        if(beta+alpha > 2*PI) {
            mincover = max(mincover, beta+alpha-2*PI);
        }
         /*angles.push_back(dd(beta-alpha, beta+alpha));
        cerr << "alpha = " << alpha << " beta = " << beta << endl;
        cerr << "Interval: [" << beta-alpha << ", " << beta+alpha << "]" << endl;*/
    }
    sort(angles.begin(), angles.end());
    for(int i=0; i < n; ++i) {
        ld in = angles[i].first;
        ld out = angles[i].second;
        if(in >= mincover) return true;
        mincover = max(mincover, out);
        if(out > maxcover) return false;
    }
    return true;
    
    
}


int main() {
    ld p;
    int n;
    while(cin >> p >> n) cout << (caso(p, n) ? "safe" : "xof!") << endl;
}
