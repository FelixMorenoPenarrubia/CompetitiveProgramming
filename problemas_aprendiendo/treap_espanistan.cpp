#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

typedef ii keyt;
typedef ll prit;


struct node {
   
    keyt x; // key
    prit y; // priority
    node* l, *r, *p;
    int cnt;
    ll sum;
    node() { }
    node (keyt key, prit prior) : x(key), y(prior), l(NULL), r(NULL), p(NULL), cnt(0) { }
    
};

typedef node* pnode;

int cnt(pnode t) {
    return t ? t->cnt : 0;
}
ll sum(pnode t) {
    return t ? t->sum : 0;
}
void upd_cnt(pnode t) {
    if(t) {
        t->cnt = 1 + cnt(t->l) + cnt(t->r);
        t->sum = t->x.first + sum(t->l) + sum(t->r);
    }
}



void split(pnode t, keyt x, pnode &l, pnode &r) {
    if(not t)
        l = r = NULL;
    else if (t->x < x) {
        split(t->r, x, t->r, r);
        l = t;
    }
    else {
        split(t->l, x, l, t->l); 
        r = t;
    }
    upd_cnt(t);
    
}
//pre: keys in t1 < keys in t2
void merge(pnode & t, pnode t1, pnode t2) { 
    if(not t1 or not t2) {
        t = t1 ? t1 : t2;
    }
    else if (t1->y < t2->y) {
        merge(t2->l, t1, t2->l);
        t = t2;
    }
    else {
        merge(t1->r, t1->r, t2);
        t = t1;
    }
    upd_cnt(t);
}

void insert_rec(pnode nt, pnode & t) {
    if(!t) {
        t = nt;
    }
    else if(t->y < nt->y) {
        pnode l, r;
        split(t, nt->x, l, r);
        t = nt;
        t->l = l;
        t->r = r;
        
    }
    else {
        if(t->x < nt->x) {
            insert_rec(nt, t->r);
        }
        else {
            insert_rec(nt, t->l);
        }
    }
    upd_cnt(t);
}
void erase_rec(keyt x, pnode &t) {
    if(!t) return;
    if(t->x == x) {
        merge(t, t->l, t->r);
    }
    else if(t->x < x) {
        erase_rec(x, t->r);
    }
    else {
        erase_rec(x, t->l);
    }
    upd_cnt(t);
}

bool search_rec(keyt x, pnode & t) {
    if(!t) return false;
    if(t->x == x) return true;
    return (x < t->x ? search_rec(x, t->l) : search_rec(x, t->r));
}
/*
void print_rec(pnode & t) {
    if(!t) return;
    print_rec(t->l);
    cout << "(" << t->x << ", " << cnt(t) << ") ";
    print_rec(t->r);
}
*/
pnode treap;

void insert(keyt x) {
    prit y = random();
    
    insert_rec(new node(x, y), treap);
}
bool search(keyt x) {
    return search_rec(x, treap);
}
/*
void print() {
    print_rec(treap);
    cout << endl;
}*/

int main() {
    int n, s, t;
    cin >> n >> s >> t;
    treap = nullptr;
    vi v(n);
    for(int i=0; i < n; ++i) cin >> v[i];
    
    ll csum = 0;
    
    for(int i=0; i < s-1; ++i) {
        csum += v[i];
        insert(ii(v[i], i));
    }
    
    ii bestsol = ii(0, s-1);
    ii bestres = ii(1e9, 1e9);
    
    for(int i=0; i+s-1 < n; ++i) {
        csum += v[i+s-1];
        insert(ii(v[i+s-1], i+s-1));
        
        int height = csum/s;
        int trash = csum%s;
        pnode t1, t2;
        split(treap, ii(height, 0), t1, t2);
        int moveg = height*cnt(t1)-sum(t1);
        merge(treap, t1, t2);
        
        ii cres = ii(trash, moveg);
        if(cres < bestres) {
            bestsol = ii(i, i+s-1);
            bestres = cres;
        }
        
        csum -= v[i];
        erase_rec(ii(v[i], i), treap);
    }
    
    cout << bestsol.first+1 << " " << bestsol.second+1 << endl;
    cout << bestres.first << " " << bestres.second << endl;
    

}

