#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll a;
	ll c;
	cin >> a >> c;

	ll ans;

	if(a > 0) {
		ll mnp = a-c/2;
		if(mnp < 0) mnp = 0;
		ll mxn = -a-(c-1)/2;
		ll mxp = a+(c-2)/2;
		ll mnn = -(a-(c-1)/2);
		if(mnn > 0) mnn = 0;

		ans = (mxp-mnp+1) + (mnn-mxn+1) - (mnp == mnn); 


	}
	else if(a < 0) {
		ll mxn = a-c/2;
		ll mnp = -a-(c-1)/2;
		if(mnp < 0) mnp = 0;
		ll mxp = -a+(c-1)/2;
		ll mnn = -a+(c-2)/2;
		if(mnn > 0) mnn = 0;

		ans = (mxp-mnp+1) + (mnn-mxn+1) - (mnp == mnn); 

	}
	else {
		ans = 1+c/2+(c-1)/2;
	}

	cout << ans << endl;
}