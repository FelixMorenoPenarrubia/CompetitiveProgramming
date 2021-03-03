#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld EPS = 1e-9;

ld solve(ld x, ld v0, ld v1, ld a, ld b) {
    ld dv = v1-v0;
    ld eqc = (-v0*dv)/b - dv*dv/(2*b) - x;
    ld eqb = v0 + v0*a/b;
    ld eqa = 0.5*(a+a*a/b);
    ld t01, t02;
    if(abs(eqa) > EPS) {
        t01 = (-eqb+sqrt(eqb*eqb-4*eqa*eqc))/(2*eqa);
        t02 = (-eqb-sqrt(eqb*eqb-4*eqa*eqc))/(2*eqa);
        if(t02 < 0) t02 = t01;
    }
    else {
        t01 = t02 = -eqc/eqb;
    }
    ld t11 = (a*t01-dv)/b;
    ld t12 = (a*t02-dv)/b;
    if(t01 < 0 or t11 < 0) return t02+t12;
    else if(t02 < 0 or t12 < 0) return t01+t11;
    return min(t01+t11, t02+t12);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ld a, b;
    cin >> a >> b;
    vector<ld> x(n+1);
    vector<ld> v(n+1);
    x[0] = 0;
    v[0] = 0;
    for(int i=0; i < n; ++i) {
        cin >> x[i+1] >> v[i+1];
    }
    
    ld ans = 0;
    
    for(int i=n-1; i > -1; --i) {
        if(v[i]*v[i]-2*b*(x[i+1]-x[i]) > 0 and v[i+1] < sqrt(v[i]*v[i]-2*b*(x[i+1]-x[i]))) {
            v[i] = sqrt(v[i+1]*v[i+1]+2*b*(x[i+1]-x[i]));
        }
    }
    
    for(int i=0; i < n; ++i) {
        if(v[i+1] > sqrt(v[i]*v[i]+2*a*(x[i+1]-x[i]))) {
            v[i+1] = sqrt(v[i]*v[i]+2*a*(x[i+1]-x[i]));
        }
        ans += solve(x[i+1]-x[i], v[i], v[i+1], a, b);
    }
    cout.setf(ios::fixed);
    cout.precision(20);
    cout << ans << endl;
    
}
