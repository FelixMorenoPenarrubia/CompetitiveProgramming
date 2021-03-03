#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<vvvd> vvvvd;
typedef vector<vvvvd> vvvvvd;
typedef vector<vvvvvd> vvvvvvd;
typedef vector<int> vi;



vvvvvd dp;


int n;
int k;
int wk;
int ie;
vi a;
vd probs;

double f(vi v) {
	int s = 0;
	for(int i=0; i < n; ++i) s += v[i];
	if(s < ie) return 0.0;
	if(s == ie) return (v == a) ? 1.0 : 0.0;
	double& res = dp[v[0]][v[1]][v[2]][v[3]][v[4]];
	if(res != -1.0) return res;
	res = 0.0;
	int mx = 0;
	for(int j=0; j < n; ++j) mx = max(v[j], mx);
	if(mx == wk) {
		int i = 0;
		for(int j=0; j < n; ++j) {
			if(mx == v[j]) i = j;
		}
		vi nv = vi(v);
		nv[i]--;
		res = f(nv)*(nv[i])/double(s-1.0);
	}
	else {
		for(int i=0; i < n; ++i) {
			if(v[i] > 0) {
				vi nv = vi(v);
				nv[i]--;
				res += f(nv)*(nv[i])/double(s-1.0);
			}
		}
	}
	return res;
}

void baq_probs(vi v, int i) {
	if(i == n) {

		//cerr << "baq_probs" << endl;
		//for(int j=0; j < n; ++j) cerr << v[j] << endl;

		int s = 0;
		for(int j=0; j < n; ++j) s += v[j];
		int mx = 0;
		for(int j=0; j < n; ++j) mx = max(v[j], mx);
		if(mx < wk && s < k) return;

		//cerr << "confirmed" << endl;

		int nummx = 0;
		for(int j=0; j < n; ++j) {
			if(v[j] == mx) {
				nummx++;
			}
		}
		for(int j=0; j < n; ++j) {
			if(v[j] == mx) {
				probs[j] += f(v)/nummx;
			}
		}
	}
	else {
		
		int s = 0;
		for(int j=0; j < n; ++j) s += v[j];
		for(int l=0; s+l <= k && (v[i]+l) <= wk; ++l) {
			vi nv = vi(v);
			nv[i] += l;
			baq_probs(nv, i+1);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout << setprecision(2);
	while(cin >> n >> k) {

		wk = k/2+1;
		a = vi(5);
		dp = vvvvvd(27, vvvvd(27, vvvd(27, vvd(27, vd(27, -1.0)))));
		ie = 0;
		for(int i=0; i < n; ++i) {
			cin >> a[i];
			ie += a[i];
		}
		probs = vd(n, 0);
		baq_probs(a, 0);

		for(int i=0; i < n; ++i) {
			cout << "pub " << i+1 << ": " << probs[i]*100 << " %\n";
		}
		
	}

}