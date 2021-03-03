#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

ll mod = 1e9+7;
set<ll> prio;

struct node {
    ii x;
    ll y;
    node* l;
    node* r;
    ll cnt;
    node(ii _x, ll _y) {
        x = _x;
        y = _y;
        cnt = 1;
        l = nullptr;
        r = nullptr;
    }
};
typedef node* pnode;
pnode treap;
vi fur;
ll cnt(pnode t) {
    return (t) ? t->cnt : 0;
}
void upd_cnt(pnode t) {
   if(t) t->cnt = 1+cnt(t->l)+cnt(t->r);
}
void split(pnode t, ii x, pnode& l, pnode& r) {
   // cerr << "SPLIT " << x.first << endl;
    if(t == nullptr) {
        l = nullptr;
        r = nullptr;
        
    }
    else if(t->x <= x) {
        split(t->r, x, t->r, r);
        l = t;
    }
    else {
        split(t->l, x, l, t->l);
        r = t;
    }
    upd_cnt(t);
}
void merge(pnode t1, pnode t2, pnode& t) { //x in t1 < x in t2
   // cerr << "MERGE" << endl;
    if(not t1) {
        t = t2;
    }
    else if (not t2) {
        t = t1;
    }
    else if(t1->y >= t2->y) {
        merge(t1->r, t2, t1->r);
        t = t1;
    }
    else {
        merge(t1, t2->l, t2->l);
        t = t2;
    }
     upd_cnt(t);
}
void insert_rec(pnode s, pnode & t) {
    if(not t) {
        t = s;
    }
    else if(t->y < s->y) {
        pnode l, r;
        split(t, s->x, l, r);
        t = s;
        t->l = l;
        t->r = r;
    }
    else if(t->x < s->x) {
        insert_rec(s, t->r);
    }
    else {
        insert_rec(s, t->l);
    }
    upd_cnt(t);
}
void erase_rec(ii x, pnode & t) {
    if(not t) return;
    if(t->x == x) {
        merge(t->l, t->r, t);
    }
    else if(t->x < x) {
        erase_rec(x, t->r);
    }
    else {
        erase_rec(x, t->l);
    }
     upd_cnt(t);
}
void insert(ii x) {
    ll y = random();
    while(prio.find(y) != prio.end()) y = random();
    prio.insert(y);
    insert_rec(new node(x, y), treap);
    upd_cnt(treap);
}
void count_rec_left(ll i, ll a, ll& r, pnode t) {
    if(not t) return;
    if(t->x.first == a) {
        r += cnt(t->r)+1;
        count_rec_left(i, a, r, t->l);
    }
    else {
        count_rec_left(i, a, r, t->r);
    }
}
void count_rec_right(ll i, ll a, ll& r, pnode t) {
    if(not t) return;
    if(t->x.first == a and t->x.second <= i) {
        r += cnt(t->l)+((t->x.second == i) ? 0 : 1);
        count_rec_right(i, a, r, t->r);
    }
    else {
        count_rec_right(i, a, r, t->l);
    }
}
void count_rec(ll i, ll a, ll& r, pnode t) {
    if(not t) return;
     //cerr << "EXPLORING: " << t->x.first << " " << t->x.second << endl;
    if(t->x.first == a and t->x.second <= i) {
    //    cerr << "FOUND FIRST NODE: " << t->x.first << " " << t->x.second << endl;
        r = (t->x.second == i) ? 0 : 1;
        count_rec_left(i, a, r, t->l);
        count_rec_right(i, a, r, t->r);
    }
    else if(t->x < ii(a, i)) {
        count_rec(i, a, r, t->r);
    }
    else {
        count_rec(i, a, r, t->l);
    }
}
ll count(ll i, ll a) {
    ll r = 0;
    count_rec(i, a, r, treap);
    return r;
}
void query(ll i, ll a) {
    if(fur[i] != a) {
        if(fur[i] != -1) erase_rec(ii(fur[i], i), treap);
        insert(ii(a, i));
        fur[i] = a;
    }
}

void print_rec(pnode t) {
    if(!t) return;
    print_rec(t->l);
    cout << "((" << t->x.first << ", " <<t->x.second << "), " << cnt(t) << ") ";
    print_rec(t->r);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    treap = nullptr;
    fur = vi(n, -1);
    for(int i=0; i < n; ++i) {
        ll x;
        cin >> x;
        query(i, x);
    }
    for(int j=0; j < q; ++j) {
        ll i, a;
        cin >> i >> a;
        cout << count(i, a) << endl;
        query(i, a);
        
    }
   // print_rec(treap);
    
}


