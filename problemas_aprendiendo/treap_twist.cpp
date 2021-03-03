#include<bits/stdc++.h>

using namespace std;


struct node {
	int x;
	int y;
	node* l;
	node* r;
	int cnt;
	bool inv;

};

typedef node* pnode;

int cnt(pnode t) {
	if(!t) return 0;
	return t->cnt;
}

void update(pnode t) {
	if(!t) return;
	t->cnt = cnt(t->l) + cnt(t->r) + 1;
}

void propagate(pnode t) {
	if(t && t->inv) {
		t->inv = false;
		if(t->l) {
			t->l->inv = !t->l->inv;
		}
		if(t->r) {
			t->r->inv = !t->r->inv;
		}
		swap(t->l, t->r);
	}
}


void split(pnode t, int x, int add, pnode& t1, pnode& t2) {
	if(!t) {
		t1 = nullptr;
		t2 = nullptr;
		return;
	}
	propagate(t);
	if(cnt(t->l)+add <= x) {
		split(t->r, x, add+cnt(t->l)+1, t->r, t2);
		t1 = t;
	}
	else {
		split(t->l, x, add, t1, t->l);
		t2 = t;
	}
	update(t1);
	update(t2);
}

void merge(pnode t1, pnode t2, pnode& t) {
	propagate(t1);
	propagate(t2);
	if(!t1 || !t2) {
		t = t1 ? (t1) : t2;
	}
	else if(t1->y < t2->y) {
		merge(t1->r, t2, t1->r);
		t = t1;
	}
	else {
		merge(t1, t2->l, t2->l);
		t = t2;
	}
	update(t);
}

void inorder_print(pnode t) {
	if(!t) return;
	propagate(t);
	inorder_print(t->l);
	cout << t->x << " ";
	inorder_print(t->r);
}

pnode treap = nullptr;

int main() {
	int n, m;
	cin >> n >> m;
	for(int i=0; i < n; ++i) {
		pnode nod = new node();
		nod->x = i+1;
		nod->y = rand();
		merge(treap, nod, treap);
	}
	for(int i=0; i < m; ++i) {
		int p, q;
		cin >> p >> q;
		--p;
		--q;
		pnode t1, t2, t3;
		split(treap, p-1, 0, t1, t2);
		split(t2, q-p, 0, t2, t3);
		propagate(t2);
		t2->inv = true;
		merge(t2, t3, t2);
		merge(t1, t2, treap);

	}

	inorder_print(treap);
	cout << endl;
}