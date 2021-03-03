#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef pair<ii, ll> iii;
typedef vector<iii> viii;

int a, b;
bool cmp1(ii x, ii y) {
    if((a*x.F+b*x.S) != (a*y.F+b*y.S)) return (a*x.F+b*x.S) < (a*y.F+b*y.S);
    else return x.S < y.S;
}
bool cmp2(ii x, ii y) {
    if((a*x.F+b*x.S) != (a*y.F+b*y.S)) return (a*x.F+b*x.S) < (a*y.F+b*y.S);
    else return x.S > y.S;
}
bool cmp1iii(iii x, iii y) {
    return cmp1(x.F, y.F);
}
bool cmp2iii(iii x, iii y) {
    return cmp2(x.F, y.F);
}
vector<iii> createVec(vector<ii> &v) {
    vector<iii> r;
    for(int i=0; i < v.size(); ++i) {
        r.push_back(iii(v[i], i));
    }
    return r;
}
int sol;
int n;

struct Node {
    vector<Node*>  v;
    map<ll, ll> m;
    Node() {
        v = vector< Node* > ();
        m = map<ll, ll>();
    }
    ~Node() {
        for(int i=0; i < v.size(); ++i) {
            delete v[i];
        }
    }
};
Node* trie;
void checkOrder(viii & vp) {
    bool good = false;
    Node* ctrie = trie;
    for(int i=0; i < vp.size(); ++i) {
        Node* nod;
        if(ctrie->m.find(vp[i].S) == ctrie->m.end()) {
            good = true;
            nod = new Node();
            int j = ctrie->v.size();
            ctrie->v.push_back(nod);
            ctrie->m[vp[i].S] = j;
        }
        else {
            nod = ctrie->v[ctrie->m[vp[i].S]];
        }
        ctrie = nod;
    }
    if(good)  {
      /*  cerr << "PERMUTATION FOUND with (a, b) = (" << a << ", " << b << ")" << endl;
        for(int i=0; i < vp.size(); ++i) cout << vp[i].S << " ";
        cout << endl;*/
        ++sol;
    }
}
void caso() {
    cin >> n;
    trie = new Node();
    
    sol = 0;
    vii v (n);
    for(int i=0; i < n; ++i) {
        int f, s;
        cin >> f >> s;
        v[i] = ii(f, s);
    }
    a = 1;
    b = 0;
    sort(v.begin(), v.end(), cmp2);
    
    /*cout << "v = " << endl;
    for(int i=0; i < n; ++i) cout << v[i].F << " " << v[i].S << endl; */
    a = 1;
    b = 1;
    viii vp = createVec(v);
    sort(vp.begin(), vp.end(), cmp1iii);
    checkOrder(vp);
    for(int i=0; i < n; ++i) {
        ii x = v[i];
        for(int j=i+1; j < n; ++j) {
            ii y = v[j];
            if(y.F > x.F and x.S >= y.S) {
                a = x.S-y.S;
                b = y.F-x.F;
                //viii vp = createVec(v);
                sort(vp.begin(), vp.end(), cmp1iii);
                checkOrder(vp);
                //vp = createVec(v);
                sort(vp.begin(), vp.end(), cmp2iii);
                checkOrder(vp);
                
            }
        }
    }
    
    cout << sol << endl;
    delete trie;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i=0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        caso();
    }
}





