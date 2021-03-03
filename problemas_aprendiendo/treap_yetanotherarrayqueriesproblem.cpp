#include<bits/stdc++.h>

using namespace std;

struct node {
    int x;
    int y;
    node* l;
    node* r;
    bool rev = false;
    int cnt = 0;
    int val;
};

typedef node* pnode;

pnode treap;

void propagate(pnode t) {
    if(t and t->rev) {
        swap(t->l, t->r);
        if(t->l) t->l->rev ^= true;
        if(t->r) t->r->rev ^= true;
        t->rev = false;
    }
}
int cnt(pnode t) {
    return t ? t->cnt : 0;
}
void upd_cnt(pnode t) {
    if(t) {
        t->cnt = cnt(t->l)+1+cnt(t->r);
    }
}

void split(pnode t, int x, pnode& t1, pnode& t2) {
    if(t == nullptr) {
        t1 = t2 = nullptr;
        return;
    }
    propagate(t);
    int count = 1+cnt(t->l);
    if (count <= x) {
        split(t->r, x-count, t->r, t2);
        t1 = t;
    }
    else {
        split(t->l, x, t1, t->l);
        t2 = t;
    }
    upd_cnt(t);
}

void merge(pnode t1, pnode t2, pnode& t) {
    if(t1 == nullptr or t2 == nullptr) {
        t = t1 ? t1 : t2;
    }
    else {
        propagate(t1);
        propagate(t2);
        if(t1->y > t2->y) {
            t = t1;
            merge(t->r, t2, t->r);
        }
        else {
            t = t2;
            merge(t1, t->l, t->l);
        }
    }
    upd_cnt(t);
}

int search(pnode t, int x) {
    if(!t) return -1;
     propagate(t);
    int count = 1+cnt(t->l);
   
    if(count < x) return search(t->r, x-count);
    if(count > x) return search(t->l, x);
    return t->val;
}
void print_node(pnode t) {
    cerr << "CNT = " << cnt(t) << " VAL = " << t->val << endl;
}

void print_treap(pnode t, string s) {
    if(t == nullptr) return;
    propagate(t);
    print_node(t);
    cerr << "Left Child ->" << endl;
    print_treap(t->l, s+'-');
    cerr << s << endl;
    cerr << "Right Child ->" << endl;
    print_treap(t->r, s+'-');
    cerr << s << endl;
}


void insert(pnode& t, pnode elem, int pos) {
    if(!t) {
        t = elem;
    }
    else {
        int count = 1+cnt(t->l);
        propagate(t);
        if(elem->y > t->y) {
            split(t, pos, elem->l, elem->r);
            t = elem;
        }
        else if(pos < count) {
            insert(t->l, elem, pos);
        }
        else {
            insert(t->r, elem, pos-count);
        }
    }
    upd_cnt(t);
}


int main() {
    int n, q, m;
    cin >> n >> q >> m;
    for(int i=0; i < n; ++i) {
        int a;
        cin >> a;
        pnode elem = new node();
        elem->y = rand();
        elem->val = a;
        insert(treap, elem, i);
        
    }
    for(int i=0; i < q; ++i) {
        int c, l, r;
        cin >> c >> l >> r;
        if(c == 1) {
            pnode interval;
            pnode firstint;
            pnode lastint;
            
            /*cerr << "BEFORE ANYTHING: " << endl;
            
            print_treap(treap, "-");
            
            cerr << endl << endl;*/
            
            
            split(treap, l-1, firstint, interval);
            split(interval, r-l+1, interval, lastint);
            pnode lastnode;
            split(interval, r-l, interval, lastnode);
            merge(lastnode, interval, interval);
            
           /* cerr << "INTERVAL AFTER CYCLIC SHIFT: " << endl;
            
            print_treap(interval, "-");
            
            cerr << endl << endl;*/
            
            merge(firstint, interval, interval);
            merge(interval, lastint, treap);
            
            /*cerr << "AFTER MERGING: " << endl;
            
            print_treap(treap, "-");
            
            cerr << endl << endl;*/
        }
        else {
            pnode interval;
            pnode firstint;
            pnode lastint;
            
            /*cerr << "BEFORE ANYTHING: " << endl;
            
            print_treap(treap, "-");
            
            cerr << endl << endl;*/
            
            
            split(treap, l-1, firstint, interval);
            split(interval, r-l+1, interval, lastint);
            interval->rev = true;
            
            /*cerr << "INTERVAL AFTER INVERSION SHIFT: " << endl;
            
            print_treap(interval, "-");
            
            cerr << endl << endl;*/
            
            merge(firstint, interval, interval);
            merge(interval, lastint, treap);
            
           /* cerr << "AFTER MERGING: " << endl;
            
            print_treap(treap, "-");
            
            cerr << endl << endl;*/
        }
    }
    for(int i=0; i < m; ++i) {
        int b;
        cin >> b;
        cout << search(treap, b) << " ";
        
       // print_treap(treap, "-");
        
    }
}
