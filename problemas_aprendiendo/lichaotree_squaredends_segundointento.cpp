#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef ll tnum;

struct point {
       tnum x;
       tnum y;
       int k;
       point() {x = 0; y = 0; k = 0;};
       point(tnum px, tnum py, int pk) {
            x = px;
            y = py;
            k = pk;
       }
};
ll INF = 1e9;
ll globalk = 0;
tnum eval(point l, tnum x) {
    if(l.k < globalk) return INF;
    return x*l.x+l.y;
}
point intersecc(point l1, point l2) {
    double a = l1.x;
    double b = l1.y;
    double c = l2.x;
    double d = l2.y;
    return point((d-b)/(a-c), (b*c-a*d)/(c-a));
}
vector<point> lichao;

void println(point l) {
    cerr << "y = " << l.x << "x + " << l.y;
}
void add(int p, int l, int r, point lin) {
    point old = lichao[p];
    
    cerr << "Interval [" << l << ", " << r << "]: " << endl;
    cerr << "Current line: ";
    println(old);
    cerr << endl << "New line: ";
    println(lin);
    cerr << endl;
    
    if(l == r) {
        if(eval(lin, l) < eval(old, l)) {
            lichao[p] = lin;
        }
    }
    else {
        int m = (l+r)/2;
        bool lowinitial = (eval(lin, l) < eval(old, l));
        bool lowm = (eval(lin, m) < eval(old, m));
        point newl;
        int nl;
        int nr;
        int np;
        if(lowinitial == lowm) {
            nl = m+1;
            nr = r;
            np = 2*p+1;
            if(lowm) {
                newl = old;
                lichao[p] = lin;
            }
            else {
                newl = lin;
            }
        }
        else {
            nl = l;
            nr = m;
            np = 2*p;
            if(lowinitial) {
                newl = lin;
            }
            else {
                newl = old;
                lichao[p] = lin;
            }
        }
        add(np, nl, nr, newl);
    }
}

int rmq(int p, int l, int r, int i) {
    if(l > i or r < i) return INF;
    if(l == r) return eval(lichao[p], i);
    
    cerr << "Interval [" << l << ", " << r << "]: " << endl;
    cerr << "Current line: ";
    println(lichao[p]);
    cerr << ", evaluated value: " << eval(lichao[p], i) << endl;
    
    return min(eval(lichao[p], i), min(rmq(2*p, l, (l+r)/2, i), rmq(2*p+1, (l+r)/2+1, r, i)));
}
void init(int n) {
    lichao = vector<point>(4*n, point(0, INF));
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    init(1e6);
    vvi dp = vvi(n+1, vi(k+1, 0));
    for(int i=1; i <= k; ++i) {
        
        
        
        
    }
}
