#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	int fc;
	cin >> fc;
	int stage = 0;
	int fnfci;
	int lnfci;
	int c;
	for(int i=1; i < n-1; i++) {
		cin >> c;
		if(stage == 0) {
			if(fc != c) {
				fnfci = i;
				lnfci = i;
				stage++;
			}
		}
		else if (stage == 1) {
			if(fc != c) lnfci = i;
		}
	}
	int lc;
	cin >> lc;
	if(fc != lc) {
		cout << n-1 << endl;
	}
	else {
		cout << max(lnfci, n-fnfci-1) << endl;
	}
}
