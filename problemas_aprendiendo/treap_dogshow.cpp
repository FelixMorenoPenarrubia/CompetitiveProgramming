#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

struct node {
    ll x;
    ll y;
    ll cnt;
    node* l;
    node* r;
    node(ll _x, ll _y) {
        x = _x;
        y = _y;
        l = nullptr;
        r = nullptr;
        cnt = 0;
    }
};

typedef node* pnode;
pnode treap;
ll cnt(pnode t) {
    return t ? t->cnt : 0;
}
void upd_cnt(pnode t) {
    if(t) t->cnt = 1 + cnt(t->r) + cnt(t->l);
}

void split(pnode t, ll x, pnode& l, pnode& r) {
    if(!t) l = r = nullptr;
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
void merge(pnode t1, pnode t2, pnode& t) {
    if(!t1 || !t2) {
        t = t1 ? t1 : t2;
    }
    else if(t1->y > t2->y) {
        t = t1;
        merge(t->r, t2, t->r);
    }
    else {
        t = t2;
        merge(t1, t->l, t->l);
    }
    upd_cnt(t);
}
void insert_rec(pnode s, pnode& t) {
    if(!t) {
        t = s;
    }
    else if (s->y > t->y) {
        split(t, s->x, s->l, s->r);
        t = s;
    }
    else if(s->x < t->x) {
        insert_rec(s, t->l);
    }
    else {
        insert_rec(s, t->r);
    }
    upd_cnt(t);
}
void insert(ll x) {
    ll y = rand();
    insert_rec(new node(x, y), treap);
}
ll count(ll x, pnode t) {
    if(!t) return 0;
    if(t->x >= x) return count(x, t->l);
    return cnt(t->l)+1+count(x, t->r);
}

int main() {
    int n;
    ll t;
    cin >> n >> t;
    treap = nullptr;
    ll sol = 0;
    for(ll i=1; i <= n; ++i) {
        ll ti;
        cin >> ti;
        insert(max(ti-i, 0LL));
        sol = max(sol, count(t-i, treap));
       // cerr << "i = " << i << " sol = " << sol << endl;
    }
    cout << sol << endl;

}
