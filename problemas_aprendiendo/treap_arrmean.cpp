#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node {
    ll x;
    ll y;
    node* l;
    node* r;
    ll sumprop;
    ll cnt;
};

typedef node* pnode;

pnode treap;

ll cnt(pnode t) {
   return t ? t->cnt : 0LL; 
}
void propagate(pnode t) {
    if(t and t->sumprop) {
        t->x += t->sumprop;
        if(t->l) t->l->sumprop += t->sumprop;
        if(t->r) t->r->sumprop += t->sumprop;
        t->sumprop = 0LL;
    }
}
void update_node(pnode t) {
    if(t) {
        t->cnt = cnt(t->l)+cnt(t->r)+1;
    }
}
void merge(pnode t1, pnode t2, pnode& t) {
    if(!t1 or !t2) t = t1 ? t1 : t2;
    else {
        
        if(t1->y > t2->y) {
            t = t1;
            merge(t->r, t2, t->r);
        }
        else {
            t = t2;
            merge(t1, t->l, t->l);
        }
        
    }
    update_node(t);
}
void split(pnode t, ll x, pnode& t1, pnode& t2) {
    if(!t) t1 = t2 = nullptr;
    else {
        propagate(t);
        if(t->x <= x) {
            split(t->r, x, t->r, t2);
            t1 = t;
        }
        else {
            split(t->l, x, t1, t->l);
            t2 = t;
        }
    }
    update_node(t);
}
ll count_geq(pnode t, ll x) {
    if(!t) return 0LL;
    propagate(t);
    if(t->x >= x) return cnt(t->r)+1LL+count_geq(t->l, x);
    else return count_geq(t->r, x);
}

void print_treap(pnode t, string s) {
    if(!t) return;
    propagate(t);
    cout << s << " x = " << t->x << " cnt = " << cnt(t) << endl;
    cout << s << "Left child: " << endl;
    print_treap(t->l, s+'<');
    cout << s << "Right child: " << endl;
    print_treap(t->r, s+'>');
}

int main() {
    int n;
    ll k;
    ll sol = 0;
    cin >> n >> k;
    for(int i=0; i < n; ++i) {
        ll x;
        cin >> x;
        pnode nod = new node();
        nod->x = 0LL;
        nod->y = rand();
        pnode t1, t2;
        split(treap, 0LL, t1, t2);
        merge(t1, nod, t1);
        merge(t1, t2, treap);
        treap->sumprop += x-k;
        propagate(treap);
        
       // cerr << "i = " << i << endl << endl;
        
     //   print_treap(treap, "");
        
        sol += count_geq(treap, 0);
        
     //   cerr << "Current sol = " << sol << endl << endl;
    }
    cout << sol << endl;
}
