#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

struct inv {
	int l;
	int r;
	int b;
	inv(int _f,int _l,int _b) {
		l = _f;
		r = _l;
		b = _b;
	}
};

void caso() {
	int n, b, f;
	cin >> n >> b >> f;
	vector<inv> intervals;
	string ot = "";
	int bl = n/16;
	if(n%16 > 0) bl++;
	char c = '0';
	char lb = '0';
	for(int i=0; i < bl; ++i) {
		for(int j=0; j < 16 and 16*i+j < n; j++) {
			ot += c;
		}
		lb = c;
		if(c == '0') c = '1';
		else c = '0';
	}
	cout << ot << endl;
	string in;
	cin >> in;
	if(in == "-1") exit(0);
	int badcount = 0;
	for(int i=0; i < n-b; i++) {
		c = in[i];
		int pi = i;
		while(i < n-b and in[i] == c) i++;
		if(i == n-b) {
			if(c == lb) {
				if(i-pi < n%16) {
					intervals.push_back(inv(n-n%16, n-1, n%16-i+pi));
				}
				else if(n % 16 == 0 and i-pi < 16) {
					intervals.push_back(inv(n-16, n-1, 16-i+pi));
				}
			}
			else {
				if(i-pi < 16) {
					intervals.push_back(inv(pi+badcount, pi+badcount+15, 16-i+pi));
					badcount += 16-(i-pi);
				}
				intervals.push_back(inv(n-n%16, n-1, n%16));
			}
		}
		else {
			if(i-pi < 16) {
				intervals.push_back(inv(pi+badcount, pi+badcount+15, 16-i+pi));
				badcount += 16-(i-pi);
			}
			
			i--;
		}
		
	}
	for(int k=0; k < 4; k++) {
		vector<inv> nintervals;
		ot = string(n, '0');
		for(int i=0; i < intervals.size(); i++) {
			int l = intervals[i].l;
			int r = intervals[i].r;
			cerr << "INTERVAL " << i << " = (" << l << ", " << r << ")" << endl;
			for(int j = l; j <= (l+r)/2; j++) {
				ot[j] = '1';
			}
		}
		cout << ot << endl;
		cin >> in;
		if(in == "-1") exit(0);
		badcount = 0;
		for(int i=0; i < intervals.size(); i++) {
			int l = intervals[i].l - badcount;
			int r = intervals[i].r - badcount;
			int ones = (l+r)/2-l+1;
			int ib = intervals[i].b;
			int cnt = 0;
			while(in[l+cnt] == '1') cnt++;
			if(ones-cnt > 0) {
				nintervals.push_back(inv(l+badcount, (l+r)/2+badcount, ones-cnt));
			}
			if(ib-(ones-cnt)> 0) {
				nintervals.push_back(inv((l+r)/2+1+badcount, r+badcount, ib-(ones-cnt)));
			}
			badcount += ib;
		}
		intervals = nintervals;
	}
	for(int i=0; i < intervals.size(); i++) {
		cout << intervals[i].l << " ";
	}
	cout << endl;
	
	
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	for(int i=0; i < t; ++i) {
		caso();
		int f;
		cin >> f;
		if(f == -1) break;
	}
}
