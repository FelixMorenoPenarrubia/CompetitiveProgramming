#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
    
    int y;
    int cnt = 0;
    string s;
    int ssiz = 0;
    int lcc = 0;
    node* l;
    node* r;
    
};

typedef node* pnode;

pnode treap = nullptr;

int cnt(pnode t) {
    if(!t) return 0;
    return t->cnt;
}
int lcc(pnode t) {
    if(!t) return 0;
    return t->lcc;
}
int ssiz(pnode t) {
    if(!t) return 0;
    return t->ssiz;
}

void upd_cnt(pnode t) {
    if(!t) return;
    t->cnt = cnt(t->l)+cnt(t->r)+1;
    t->lcc = lcc(t->l) + ssiz(t) + lcc(t->r);
}

void printtreap(pnode t) {
    if(!t) return;
    cerr << "current node: " << t->s << endl; 
    cerr << "lcc(t->l) = " << lcc(t->l) << endl;
    cerr << "lcc(t) = " << lcc(t) << endl;
    cerr << "lcc(t->r) = " << lcc(t->r) << endl;
    printtreap(t->l);
    printtreap(t->r);
     cerr << "end node: " << t->s << endl; 
}

void split(pnode t, int x, pnode& t1, pnode& t2, int count) {
    
 //  cerr << "split" << endl;
    
    if(!t) {
        t1 = t2 = nullptr;
        return;
    }
  //  cerr << "cnode: " << t->s << endl;
    if(cnt(t->l)+count+1 < x) {
        t1 = t;
        split(t->r, x, t1->r, t2, count+cnt(t->l)+1);
    }
    else {
        t2 = t;
        split(t->l, x, t1, t->l, count);
    }
    upd_cnt(t1);
    upd_cnt(t2);
}

void merge(pnode t1, pnode t2, pnode& t) {
    
 //   cerr << "merge" << endl;
    
    if(!t1) t = t2;
    else if(!t2) t = t1;
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
    upd_cnt(t);
}

void insert(string s, int i) {
    pnode n = new node();
    n->y = rand();
    n->s = s;
    n->ssiz = s.length();
    pnode t1, t2;
    t1 = nullptr;
    t2 = nullptr;
    split(treap, i+1, t1, t2, 0);
    
   /* cerr << "AFTER SPLIT" << endl;
    cerr << "t1 : " << endl;
    printtreap(t1);
    cerr << "t2 : " << endl;
    printtreap(t2);
    */
    merge(t1, n, t1);
    
   /* cerr << "AFTER FIRST MERGE" << endl;
    cerr << "t1 : " << endl;
    printtreap(t1);
    cerr << "t2 : " << endl;
    printtreap(t2);*/
    
    merge(t1, t2, treap);
}

char searchchar(pnode t, int c) {
    
   /* cerr << "search " << c << endl;
    cerr << "current node: " << t->s << endl; 
    cerr << "lcc(t->l) = " << lcc(t->l) << endl;
    cerr << "lcc(t) = " << lcc(t) << endl;
    cerr << "lcc(t->r) = " << lcc(t->r) << endl;*/
    if(lcc(t->l) > c) {
        return searchchar(t->l, c);
    }
    else if(lcc(t->l)+ssiz(t) > c) {
        return t->s[c-lcc(t->l)];
    }
    else {
        return searchchar(t->r, c-lcc(t->l)-ssiz(t));
    }
}



int main() {
    char ins;
    string ans = "";
    while(cin >> ins) {
        if(ins == 'E') break;
        if(ins == 'I') {
            string s;
            int i;
            cin >> s >> i;
            insert(s, i);
        }
        else if(ins == 'C') {
            int c;
            cin >> c;
            ans += searchchar(treap, c);
        }
    }
   // printtreap(treap);
    cout << ans << endl;
}
