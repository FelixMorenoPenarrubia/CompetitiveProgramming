#include<bits/stdc++.h> 

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

vi am;
vvvi ambysubs;
int n;


int pc(int x) {
	int r = 0;
	while(x > 0) {
		r += x&1;
		x >>= 1;
	}
	return r;
}

void check() {
	int nsubs = 0;
	for(int m=0; m < (1<<n); ++m) {
		int neigh = 0;
		for(int i=0; i < n; ++i) {
			if(m&(1<<i)) neigh |= am[i];
		}
		if(pc(neigh) >= pc(m)) nsubs++;
	}

	if(ambysubs[nsubs].empty()) {
		cout << "nsubs = " << nsubs << endl;
		vi a = am;
			for(int j=0; j < n; ++j) {
				for(int k=0; k < n; ++k) {
					cout << ((a[j]&(1<<k)) ? 1 : 0);
				}
				cout << endl;
			}
			cout << endl;
	  ambysubs[nsubs].push_back(am); 
	}
}

void baq(int i) {
	if(i == n) {
		check();
		return;
	}
	for(int m=0; m < (1<<n); ++m) {
		am[i] = m;
		baq(i+1);
	}
}


int main() {
	cin >> n;
	am = vi(n);
	ambysubs = vvvi((1<<n) + 1, vvi());
	baq(0);
	for(int i=1; i <= (1<<(n-1)); i+=2) {
		cout << "AM by subs: " << i << endl;
		for(int l=0; l < /*(int)ambysubs[i].size()*/1; ++l) {
			vi a = ambysubs[i][l];
			for(int j=0; j < n; ++j) {
				for(int k=0; k < n; ++k) {
					cout << ((a[j]&(1<<k)) ? 1 : 0);
				}
				cout << endl;
			}
			cout << endl;
		}
	}
}