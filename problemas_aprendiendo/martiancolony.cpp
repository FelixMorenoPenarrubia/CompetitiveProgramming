#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> pi;



typedef ld T;

struct Pt {
    T x, y;
    int id;
    Pt(T a, T b) : x(a), y(b) {}
    Pt() {}
};
inline bool EQ(T a, T b) { return abs(a-b) < 1e-6; }

inline Pt operator-(Pt a, Pt b) {
    return Pt(a.x-b.x, a.y-b.y);
}

inline bool operator==(Pt a, Pt b) {
    return EQ(a.x, b.x) and EQ(a.y, b.y);
}
inline bool operator<(Pt a, Pt b) {
    return EQ(a.x, b.x) ? a.y < b.y : a.x < b.x;
}

inline ld operator^(Pt a, Pt b) {
    return a.x*b.y-a.y*b.x;
}

inline ld area2(Pt a, Pt b, Pt c) {
    return (b-a)^(c-a);
}

pair<vector<Pt>, vector<Pt> > convex_hull(vector<Pt>& v) {
    int n = v.size(), k1 =0, k2 = 0;
    vector<Pt> L(n), U(n);
    sort(v.begin(), v.end());
    for(int i=0; i < n; ++i) {
        while(k1 >= 2 and area2(L[k1 - 2], L[k1 -1], v[i]) <= 0) --k1;
        while(k2 >= 2 and area2(U[k2 - 2], U[k2 -1], v[i]) >= 0) --k2;
        L[k1++] = U[k2++] = v[i];
    }
    L.resize(k1);
    U.resize(k2);
    return {L, U};
}

vector<Pt> unify(pair<vector<Pt>, vector<Pt> > CH) {
    for(int i= CH.second.size()-2; i >= 1; --i) {
        CH.first.push_back(CH.second[i]);
    }
    return CH.first;
}





int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ld r;
    cin >> r;
    vector<Pt> vpt (n);
    for(int i=0; i < n; ++i) {
        cin >> vpt[i].x >> vpt[i].y;
    }
    vector<Pt> chu = unify(convex_hull(vpt));
    
    
}
