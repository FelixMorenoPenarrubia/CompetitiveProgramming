#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<ld, ld> dd;

struct node {
    node* l;
    node* r;
    ld x;
    int y;
    ld m;
    ld b;
    ld cm;
    ld cb;
};

typedef node* pnode;

pnode treap = nullptr;

ld cm(pnode t) {
    if(t == nullptr) return 0.0;
    return t->cm;
}
ld cb(pnode t) {
    if(t == nullptr) return 0.0;
    return t->cb;
}
void upd(pnode t) {
    if(t == nullptr) return;
    t->cm = cm(t->l)+t->m+cm(t->r);
    t->cb = cb(t->l)+t->b+cb(t->r);
}



void split(pnode t, ld x, pnode& t1, pnode& t2) {
    if(t == nullptr) { 
        t1 = t2 = nullptr;
    }
    else if(t->x < x) {
       
        split(t->r, x, t->r, t2); 
         t1 = t;
    }
    else {
       
        split(t->l, x, t1, t->l);
        t2 = t;
    }
    upd(t1);
    upd(t2);
}

void merge(pnode t1, pnode t2, pnode& t) {
    if(t1 == nullptr) {
        t = t2;
    }
    else if (t2 == nullptr) {
        t = t1;
    }
    else if (t1->y > t2->y) {
        
        merge(t1->r, t2, t1->r);
        t = t1;
    }
    else {
        
        merge(t1, t2->l, t2->l);
        t = t2;
    }
    upd(t);
}

void insert(ld x, ld m, ld b) {
    pnode t = new node();
    t->x = x;
    t->y = rand();
    t->m = m;
    t->b = b;
    t->cm = m;
    t->cb = b;
    pnode t1, t2, t3;
    t1 = nullptr;
    t2 = nullptr;
    t3 = nullptr;
    split(treap, x, t1, t2);
    merge(t1, t, t3);
    merge(t3, t2, treap);
}
void consult(pnode t, ld x, ld& m, ld& b) {
    if(t == nullptr) return;
    
   // cerr << "Consult : " << endl;
    //cerr << "Current node: x = " << t->x << " m = " << t->m << " b = " << t->b << " cm = " << t->cm << " cb = " << t->cb << endl;
    
    if(t->x > x) {
        consult(t->l, x, m, b);
        
    }
    else {
        m += t->m+cm(t->l);
        b += t->b+cb(t->l);
        
        //cerr << "To the left. Current m = " << m << " b = " << b << endl;
        
        consult(t->r, x, m, b);
    }
    
}
ld EPS = 1e-4;
int main() {
    int n;
    cout.setf(ios::fixed);
    cout.precision(3);
    while(cin >> n) {
        treap = nullptr;
        for(int i=0; i < n; ++i) {
            char c;
            cin >> c;
            if(c == 'A') {
                ld l, r, yl, yr;
                cin >> l >> r >> yl >> yr;
                ld m = (yr-yl)/(r-l);
                ld b = yr-r*m;
                insert(l, m, b);
                insert(r, -m, -b);
            }
            else if(c == 'C') {
                ld m = 0.0;
                ld b = 0.0;
                ld x;
                cin >> x;
                consult(treap, x, m, b);
                ld ans = m*x+b;
                if(ans < -EPS) {
                    vector<ld> destroyer = vector<ld>(1e9, 0);
                    
                  //  cerr << "AAAAAAAA" << endl;
                    
                }
                if(ans < EPS) cout << "0.000" << endl; 
                else cout << ans << endl;
            }
        }
    }
}
