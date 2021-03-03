#include<bits/stdc++.h>

#define SZ (int)v.size()
using namespace std;

typedef vector<int> vi;

const int concat = -1e5;
const int sum = -1e5+1;
const int sub = -1e5+2;
const int prod = -1e5+3;

set<int> ans;

int eval(vi v) {

	/*cerr << "eval" << endl;
	for(auto x : v) {
		cerr << x << " ";
	}
	cerr << endl;*/

	for(int i=0; i < SZ; ++i) {
		if(v[i] == concat) {
			vi newv = vi(SZ-2);
			for(int j=0; j < i; ++j) {
				newv[j] = v[j];
			}
			newv[i-1] = 10*newv[i-1]+v[i+1];
			for(int j=i; j+2 < SZ; ++j) {
				newv[j] = v[j+2];
			}
			v = newv;
			i--;
		}
	}
	for(int i=0; i < SZ; ++i) {
		if(v[i] == prod) {
			vi newv = vi(SZ-2);
			for(int j=0; j < i; ++j) {
				newv[j] = v[j];
			}
			newv[i-1] = newv[i-1]*v[i+1];
			for(int j=i; j+2 < SZ; ++j) {
				newv[j] = v[j+2];
			}
			v = newv;
			i--;
		}
	}
	for(int i=0; i < SZ; ++i) {
		if(v[i] == sum) {
			vi newv = vi(SZ-2);
			for(int j=0; j < i; ++j) {
				newv[j] = v[j];
			}
			newv[i-1] = newv[i-1]+v[i+1];
			for(int j=i; j+2 < SZ; ++j) {
				newv[j] = v[j+2];
			}
			v = newv;
			i--;
		}
		else if(v[i] == sub) {
			vi newv = vi(SZ-2);
			for(int j=0; j < i; ++j) {
				newv[j] = v[j];
			}
			newv[i-1] = newv[i-1]-v[i+1];
			for(int j=i; j+2 < SZ; ++j) {
				newv[j] = v[j+2];
			}
			v = newv;
			i--;
		}


		
	}

	//cerr << "result = " << v[0] << endl;
	return v[0];
}

void baq(int i, vi& v) {
	if(i == 7) {
		if((!(v[1] == concat && v[3] == concat && v[5] == concat)) && (eval(v) >= 0)) ans.insert(eval(v));
	}
	else {
		v[i] = concat;
		baq(i+2, v);
		v[i] = prod;
		baq(i+2, v);
		v[i] = sum;
		baq(i+2, v);
		v[i] = sub;
		baq(i+2, v);
	}
}

int main() {
	vi a(4);
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(a.begin(), a.end());
	do {
		vi v(7);
		for(int i=0; i < 4; ++i) {
		//	cerr << a[i] << " ";
			v[2*i] = a[i];
		}
		//cerr << endl;
		baq(1, v);
		//cerr << "----" << endl;
	} while(next_permutation(a.begin(), a.end()));

	/*for(auto x : ans) {
		cerr << x << " ";
	}*/
	//cerr << endl;
	cout << ans.size() << endl;
}