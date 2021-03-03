#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
	ll x;
	ll y;
	node* l;
	node* r;
	ll cnt;
	ll sum;
};

node* treap;


ll sum(node* t) {
	if(t) return t->sum;
	return 0;
}

ll cnt(node* t) {
	if(t) return t->cnt;
	return 0;
} 

void update(node* t) {
	if(!t) return;
	t->cnt = cnt(t->l) + cnt(t->r) + 1;
	t->sum = (sum(t->l) + sum(t->r) + t->x)%ll(1e9);
}

void split(node* t, ll x, node*& t1, node*& t2) {
	if(!t) {
		t1 = nullptr;
		t2 = nullptr;
		return;
	}
	if(t->x <= x) {
		split(t->r, x, t->r, t2);
		t1 = t;
	}
	else {
		split(t->l, x, t1, t->l);
		t2 = t;
	}
	update(t1);
	update(t2);
}

//t1.x < t2.x
void merge(node* t1, node* t2, node*& t) {
	if(!t1) {
		t = t2;
		
	}
	else if(!t2 || !t1) {
		t = t1;
		
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

void split_search(node* t, ll i, node*& t1, node*& t2) {
	if(!t) {
		t1 = nullptr;
		t2 = nullptr;
		return;
	}
	if(cnt(t->l) < i) {
		split_search(t->r, i-cnt(t->l)-1, t->r, t2);
		t1 = t;
	}
	else {
		split_search(t->l, i, t1, t->l);
		t2 = t;
	}
	update(t1);
	update(t2);
}
bool search(node* t, ll x) {
	if(!t) return false;
	if(t->x > x) {
		return search(t->l, x);
	}
	else if(t->x < x) {
		return search(t->r, x);
	}
	else return true;
}

void delete_tree(node *t) {
	if(!t) return;
	delete_tree(t->l);
	delete_tree(t->r);
	delete t;
}
void insert(ll x) {
	node* n = new node();
	n->x = x;
	n->y = rand();
	node* t1;
	node* t2;
	split(treap, x, t1, t2);
	merge(t1, n, t1);
	merge(t1, t2, treap);
}



int main() {
	int m;
	cin >> m;
	while(m != 0) {
		
		delete_tree(treap);
		treap = nullptr;
		insert(0);
		for(int t=0; t < m; ++t) {
			ll y, i, j;
			cin >> y >> i >> j;
			node* t1, *t2, *t3;
			split_search(treap, i-1, t1, t2);
			split_search(t2, j-i+1, t2, t3);

			ll z = y + sum(t2);
			z %= ll(1e9);
			merge(t1, t2, t2);
			merge(t2, t3, treap);
			if(search(treap, z)) {
				cout << "R " << z << endl;
			}
			else {
				insert(z);
				cout << "I " << z << endl;
			}
		}
		cout << string(10, '-') << endl;
		cin >> m;
	}
	//cout << string(10, '-') << endl;
}