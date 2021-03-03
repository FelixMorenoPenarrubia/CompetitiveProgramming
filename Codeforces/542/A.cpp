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
	int pos = 0;
	int zer = 0;
	for(int i=0; i < n; i++) {
		int a;
		cin >> a;
		if(a > 0) pos++;
		if(a == 0) zer++;
	}
	int mn = n/2;
	if(n%2) mn++;
	if(pos >= mn) {
		cout << 1 << endl;
	}
	else if(n-pos-zer >= mn) {
		cout << -1 << endl;
	}
	else {
		cout << 0 << endl;
	}
}
