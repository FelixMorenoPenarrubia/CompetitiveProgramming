#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

typedef ll keyt;
typedef ll prit;

ll mod = 1e9;

struct node {
    node* l, *r, *p;
    keyt x; // key
    prit y; // priority
    int cnt;
    ll sum;
    node() { }
    node (keyt key, prit prior) : x(key), y(prior), l(NULL), r(NULL), p(NULL), cnt(0), sum(x) { }
    
};

typedef node* pnode;

int cnt(pnode t) {
    return t != NULL ? t->cnt : 0;
}
ll tsum(pnode t) {
    return t != NULL ? t->sum : 0;
}
void upd_cnt(pnode t) {
    if(t != NULL) {
        t->cnt = 1 + cnt(t->l) + cnt(t->r);
        t->sum = (t->x+tsum(t->l)+tsum(t->r))%mod;
    }
}


//prit random() {
    
//}

void split(pnode t, keyt x, pnode &l, pnode &r) {
    if( t == NULL)
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
    if( t1 == NULL or t2 == NULL) {
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
    if(t == NULL) {
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
    if(t == NULL) return;
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
    if(t == NULL) return false;
    if(t->x == x) return true;
    return (x < t->x ? search_rec(x, t->l) : search_rec(x, t->r));
}

void print_rec(pnode & t) {
    if(!t) return;
    print_rec(t->l);
    cout << "(" << t->x << ", " << cnt(t) << ") ";
    print_rec(t->r);
}

pnode treap;

ll sum_rec(pnode t, int l, int r, int i, int j) {
    if(r < i or l > j or t == NULL) return 0;
    if(l >= i and r <= j) return tsum(t);
   // cout << "sum_rec(" << l << ", " << r << ", " << i << ", " << j <<"): cval = " << t->x << " csum = " << tsum(t) << " cnt of left = " << cnt(t->l) << endl;
    if(l+cnt(t->l) >= i and l +cnt(t->l) <= j) return (t->x+sum_rec(t->l, l, l+cnt(t->l)-1, i, j)+sum_rec(t->r, l+cnt(t->l)+1, r, i, j))%mod;
    else return (sum_rec(t->l, l, l+cnt(t->l)-1, i, j)+sum_rec(t->r, l+cnt(t->l)+1, r, i, j))%mod;
}

ll sum(int i, int j) {
    return sum_rec(treap, 0, cnt(treap)-1, i, j);
}
void insert(keyt x) {
    prit y = rand();
    
    insert_rec(new node(x, y), treap);
}
bool search(keyt x) {
    return search_rec(x, treap);
}
void print() {
    print_rec(treap);
    cout << endl;
}
void caso(int m) {
    treap = NULL;
    insert(0);
    for (int k=0; k < m; ++k) {
       // print();
        ll y;
        int i, j;
        cin >> y >> i >> j;
        --i;
        --j;
        ll z = (y + sum(i, j))%mod;
        if (search(z)) {
            cout << "R " << z << endl;
        }
        else {
            cout << "I " << z << endl;
            insert(z);
        }
    }
    cout << "----------" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    while(m != 0) {
        caso(m);
        cin >> m;
    }
    

}

