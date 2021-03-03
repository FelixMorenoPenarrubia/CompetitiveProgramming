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
    int t;
    cin >> t;
    for(int k=0; k < t; ++k) {
		string s;
		cin >> s;
		string a,  b;
		a = "";
		b = "";
		int j = 1;
		if(s[0] == '1') {
			j = 0;
			a += '1';
		}
		else if(s[0] == '5') {
			a += '3';
			b += '2';
		}
		else {
			a += char(s[0]-1);
			b += '1';
		}
		for(int i=1; i < s.length(); ++i) {
			if(s[i] == '4') {
				a += '3';
				b += '1';
			}
			else {
				a += s[i];
				b += '0';
			}
			++j;
		}
		cout << "Case #" << k+1 << ": " << a << " " << b << endl;
	}
}
