#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int INF = 1e7;

struct node {
  //  int x;
    int y;
    node* l;
    node* r;
    int cnt;
    int cpos;
    int rankL;
    int rankR;
    int winsK;
    int orposK;
    int leftTR;
    int rightTL;
    int maxL;
    int maxR;
    int maxwK;
    ii maxleftK;
    bool threatR;
    bool threatL;
    node() {
        cpos = 0;
        y = rand();
        l = nullptr;
        r = nullptr;
        cnt = 0;
        winsK = 0;
        leftTR = INF;
        rightTL = -1;
        maxL = -1;
        maxR = -1;
    }
};

typedef node* pnode;


pnode treap;
int n;
int c;
int rankK;




int cnt(pnode t) {
    return t ? t->cnt : 0;
}
int ltr(pnode t) {
    return t ? t->leftTR : INF;
}
int rtl(pnode t) {
    return t ? t->rightTL : -1;
}
ii mlk(pnode t) {
    return t ? t->maxleftK : ii(0, INF);
}
int maxl(pnode t) {
    return t ? t->maxL : -1;
}
int maxr(pnode t) {
    return t ? t->maxR : -1;
}
bool thrl(pnode t) {
    return t ? t->threatL : false;
}
bool thrr(pnode t) {
    return t ? t->threatR : false;
}
int maxwk(pnode t) {
    return t ? t->maxwK : -1;
}
void upd_cnt(pnode t) {
    if(t) {
        t->cnt = cnt(t->l)+cnt(t->r)+1;
        t->leftTR = (t->rankL > rankK ? t->cpos : INF);
        t->leftTR = min(t->leftTR, min(ltr(t->l), ltr(t->r)));
        t->rightTL = (t->rankR > rankK ? t->cpos : -1);
        t->rightTL = max(t->rightTL, max(rtl(t->l), rtl(t->r)));
        t->maxleftK = ii(t->winsK, t->orposK);
        ii mlkl = mlk(t->l);
        ii mlkr = mlk(t->r);
        ii cmlk = t->maxleftK;
        if(mlkl.first > cmlk.first or (mlkl.first == cmlk.first and mlkl.second < cmlk.second)) {
            cmlk = mlkl;
        }
        if(mlkr.first > cmlk.first or (mlkr.first == cmlk.first and mlkr.second < cmlk.second)) {
            cmlk = mlkr;
        }
        t->maxleftK = cmlk;
        t->maxL = max(t->rankL, max(maxl(t->l), maxl(t->r)));
        t->maxR = max(t->rankR, max(maxr(t->l), maxr(t->r)));
        t->threatL = thrl(t->l) or thrl(t->r) or (t->rankL > rankK);
        t->threatR = thrr(t->l) or thrr(t->r) or (t->rankR > rankK);
        t->maxwK = max(t->winsK, max(maxwk(t->l), maxwk(t->r)));
    }
}

void print_node(pnode t) {
    
    cerr << "L = " << t->rankL << " R = "<< t->rankR << endl;
    cerr << "winsK = " << t->winsK << " orposK = " << t->orposK << endl << endl;
}

void print_rec(pnode & t, int add) {
    return;
    if(!t) return;
    print_rec(t->l, add);
    cerr << "#Current pos: " << add+cnt(t->l) << endl;
    print_node(t);
    print_rec(t->r, add+cnt(t->l)+1);
}

void split(pnode t, pnode& l, pnode& r, int x, int add) {
    if(!t) return void (l = r = nullptr);
    int cx = cnt(t->l) + add;
  //  cerr << "Splitting! cx = " << cx << endl << endl;
   // print_node(t);
    t->cpos = cx;
    if(cx < x) {
        split(t->r, t->r, r, x, cx+1);
        l = t;
    }
    else {
        split(t->l, l, t->l, x, add);
        r = t;
    }
    upd_cnt(t);
}



void merge(pnode t1, pnode t2, pnode& t) {
    if(!t1 || !t2) {
        t = t1 ? t1 : t2;
    }
    else if(t1->y > t2->y) {
        merge(t1->r, t2, t1->r);
        t = t1;
    }
    else {
        merge(t1, t2->l, t2->l);
        t = t2;
    }
    upd_cnt(t);
}
void insert(pnode t) {
    pnode t1, t2;
    split(treap, t1, t2, t->cpos, 0);
    merge(t1, t, t1);
    merge(t1, t2, treap);
}
void leftTRsearch(pnode t, int add, int& leftTR) {
    if(!t) return;
    int cx = cnt(t->l) + add;
    if(t->rankR > rankK) leftTR = min(leftTR, cx);
    if(thrr(t->l)) {
        leftTRsearch(t->l, add, leftTR);
    }
    else {
        leftTRsearch(t->r, cx+1, leftTR);
    }
}
void rightTLsearch(pnode t, int add, int& rightTL) {
    if(!t) return;
    int cx = cnt(t->l) + add;
    if(t->rankL > rankK) rightTL = max(rightTL, cx);
    if(thrl(t->r)) {
        rightTLsearch(t->r, cx+1, rightTL);
    }
    else {
        rightTLsearch(t->l, add, rightTL);
    }
}
void maxleftKsearch(pnode t, int add, ii& maxleftK) {
    if(!t) return;
    int cx = cnt(t->l) + add;
    if(t->winsK > maxleftK.first or (t->winsK == maxleftK.first and t->orposK < maxleftK.second)) {
        maxleftK.first = t->winsK;
        maxleftK.second = t->orposK;
    }
    if(maxwk(t->l) >= maxwk(t->r)) {
        maxleftKsearch(t->l, add, maxleftK);
    }
    else {
        maxleftKsearch(t->r, cx+1, maxleftK);
    }
}

int main() {
    treap = nullptr;
    cin >> n >> c >> rankK;
    vector<int> k (n-1);
    for(int i=0; i < n-1; ++i) cin >> k[i];
    for(int i=0; i < n; ++i) {
        pnode t = new node();
        t->cpos = i;
        t->rankL = (i > 0) ? k[i-1] : -1;
        t->rankR = (i < n-1) ? k[i] : -1;
        t->orposK = i;
        insert(t);
    }
    ii sol = ii(-1, 0);
    
    print_rec(treap, 0);
    
    for(int i=0; i < c; ++i) {
       int a, b;
       cin >> a >> b;
       pnode t1, t2, t3;
       split(treap, t1, t2, a, 0);
       split(t2, t2, t3, b-a+1, 0);
       pnode t = new node();
       t->cpos = a;
       t->rankL = t2->maxL;
       t->rankR = t2->maxR;
       /*int leftTR = t2->leftTR;
       int rightTL = t2->rightTL;*/
       int leftTR = INF;
       int rightTL = -1;
       leftTRsearch(t2, 0, leftTR);
       rightTLsearch(t2, 0, rightTL);
       
      /* cerr << "leftTR = " << leftTR << "rightTL = " << rightTL << endl;
       cerr << "Printing t2: " << endl << endl;*/
       print_rec(t2, 0);
       
       if(rightTL < leftTR) {
          int ap = max(0, rightTL);
          int bp = min(b-a, leftTR);
          pnode tp1, tp2, tp3;
          split(t2, tp1, tp2, ap, 0);
          split(tp2, tp2, tp3, bp-ap+1, 0);
          ii cmlk = ii(0, INF);
          maxleftKsearch(tp2, 0, cmlk);
          t->winsK = cmlk.first+1;
          t->orposK = cmlk.second;
          if(cmlk.first+1 > sol.first or (cmlk.first == sol.first and cmlk.second < sol.second)) sol = cmlk;
       }
       else {
          t->winsK = -INF;
          t->orposK = INF;
       }
       merge(t1, t3, treap);
       insert(t);
       
       print_rec(treap, 0);
    }
    cout << sol.second << endl;
}
