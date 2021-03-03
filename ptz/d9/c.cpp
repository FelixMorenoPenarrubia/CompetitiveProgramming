#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct pt {
	int x, y;
	int c;
	int id;
	
};

bool operator <(const pt a, const pt b) {
		if(a.y == b.y) {
			if(a.x == b.x) return a.id < b.id;
		 	return a.x < b.x;
		}
		return a.y < b.y;
	}

bool xcomp(const pt& a, const pt& b) {
		if(a.x == b.x) return a.y < b.y;
		return a.x < b.x;
}

const int INF = 1e9;
const int MAX_COORD = 3e5;
int n, k;
vector<set<pt> > cpc;
vector<pt> v;
vi st;
vi lazy;


void init_st() {
	st = vi(4*MAX_COORD, 0);
	lazy = vi(4*MAX_COORD, 0);
}


void propagate(int p, int l, int r) {
	st[p] += lazy[p];
	if(l < r) {
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += lazy[p];
	}
	lazy[p] = 0;
}

void update(int p, int l, int r, int i, int j, int val) {
	if(l > j || r < i) return;
	propagate(p, l, r);
	if(l >= i && r <= j) {
		lazy[p] += val;
		propagate(p, l, r);
	}
	else {
		update(2*p, l, (l+r)/2, i, j, val);
		update(2*p+1, (l+r)/2+1, r, i, j, val);
		st[p] = max(st[2*p], st[2*p+1]);
	}
}

int rmq(int p, int l, int r, int i, int j) {
	if(l > j || r < i) return -1;
	propagate(p, l, r);
	if(l >= i && r <= j) {
		return st[p];
	}
	else {
		return max(rmq(2*p, l, (l+r)/2, i, j),
		rmq(2*p+1, (l+r)/2+1, r, i, j));
	}
}

void add_point(int i, int d) {

//	cerr << "Adding point " << v[i].x << " " << v[i].y << " " << v[i].c << endl;

	cpc[v[i].c].insert(v[i]);
	auto it = cpc[v[i].c].find(v[i]);
	it--;
	int ly = it->y+d+1;
	it++;
	it++;
	int uy = it->y-d-1;
	ly = max(ly, max(0, v[i].y-d));
	uy = min(uy, min(MAX_COORD, v[i].y+d));
	if(ly <= uy) {
		update(1, 0, MAX_COORD, ly, uy, 1);
	}
}

void remove_point(int i, int d) {
	
	auto it = cpc[v[i].c].find(v[i]);
	it--;
	int ly = it->y+d+1;
	it++;
	it++;
	int uy = it->y-d-1;
	ly = max(ly, max(0, v[i].y-d));
	uy = min(uy, min(MAX_COORD, v[i].y+d));
	if(ly <= uy) {
		update(1, 0, MAX_COORD, ly, uy, -1);
	}

	cpc[v[i].c].erase(cpc[v[i].c].find(v[i]));
}



bool check_possible(int d) {

	//cerr << "ini d = " << d << endl;

	cpc = vector<set<pt> > (k);

	for(int i=0; i < k; ++i) {
		pt p1;
		p1.y = -INF;
		pt p2;
		p2.y = INF;
		cpc[i].insert(p1);
		cpc[i].insert(p2);
	}

	init_st();
	int pid = 0;
	for(int i=0; i < n; ++i) {
		int up_x = v[i].x+d;
		while(pid < n && v[pid].x <= up_x) {
			add_point(pid, d);
			pid++;
		}

	//	cerr << "iteration " << i << " rmq = " << rmq(1, 0, MAX_COORD, 0, MAX_COORD) << endl;

		if(rmq(1, 0, MAX_COORD, 0, MAX_COORD) == k) {
			return true;
		}

		remove_point(i, d);
	}
	return false;
}

int main() {
	
	cin >> n >> k;

	v = vector<pt>(n);
	for(int i=0; i < n; ++i)  {
		cin >> v[i].x >> v[i].y >> v[i].c;
		v[i].y *= 2;

		v[i].c--;
		v[i].id = i;
	}

	sort(v.begin(), v.end(), xcomp);


	int l = -1;
	int r = 5;
	while(r-l > 1) {
		int mid = (l+r)/2;
		if(check_possible(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}

	cout << r << endl;


}