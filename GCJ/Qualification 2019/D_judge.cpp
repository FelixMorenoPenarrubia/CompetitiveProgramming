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
	cout << 1 << endl;
	int n = 5;
	int b = 2;
	int f = 5;
	string s = "01101";
	cout << n <<" "<<  b << " "<< f<<endl;
	string in;
	while(cin >> in) {
		string out = "";
		for(int i=0; i < n; i++) {
			if(s[i] == '1') out += in[i];
		}
		cout << out << endl;
		f--;
		if(f == 0) break;
	}
	vi bl = vi(b);
	for(int i=0; i < b; i++) {
		int cb;
		cin >> cb;
		if (s[cb] == 1) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	
}
