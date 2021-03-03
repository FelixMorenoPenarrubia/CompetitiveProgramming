#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

const lll g = 42;
const lll MOD = 1000000000000000031LL;




int main() {
	int n;
	cin >> n;
	n = 1000000-n;
	lll ans = 300;
	
	vector<lll> ptg(80);
	ptg[0] = 1;
	ptg[1] = g;
	for(int i=2; i < 80; ++i) {
		ptg[i] = (ptg[i-1]*ptg[i-1])%MOD;
	}

	for(int i=0; i < n; ++i) {
		lll nans = 1;
		for(lll j=0; (((lll)1)<<j) <= ans; ++j) {
			if((((lll)1)<<j)&ans)  {
				nans *= ptg[j+1];
				nans %= MOD;
			}
		}
		ans = nans;
	}

	cout << ((ll)ans) << endl;


}