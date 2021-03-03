#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--) {
		ll l, r;
		cin >> l >> r;
		if(2*l > r) {
			cout << "0\n";
		}
		else {
			cout << ((r-2*l+1)*(r-2*l+2))/2 << "\n";
		}
	}
}