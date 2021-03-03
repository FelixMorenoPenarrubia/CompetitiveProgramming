#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

const lll g = 42;
const lll MOD = 1000000000000000031LL;


lll pot(lll e) {
	if(e == 0) return 1;
	lll sq = pot(e/2);
	if(e%2 == 1) return (((sq*sq)%MOD)*g)%MOD;
	return (sq*sq)%MOD;
}

int main() {
	int n;
	cin >> n;
	n = 1000000-n;
	lll ans = 300;
	for(int i=0; i < n; ++i) {
		ans = pot(ans);
	}
	cout << ((ll)ans) << endl;


}