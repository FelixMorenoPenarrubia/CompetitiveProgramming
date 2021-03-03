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
	string s;
	cin >> s;
	int open = 0;
	int closed = 0;
	if(s[0] == ')' or n%2 == 1) {
		cout << ":(" << endl;
		return 0;
	}
	for(int i=0; i < n; i++) {
		if(s[i] == '(') open++;
		else if(s[i] == ')') closed++;
	}
	for(int i=0; i < n; i++) {
		if(s[i] == '?') {
			if(open < n/2) { s[i] = '('; open++; }
			else s[i] = ')';
		}
	}
	int copen = 0;
	if(n > 2 and s[n-2] == '(') {
		cout << ":(" << endl;
		return 0;
	}
	for(int i=0; i < n; i++) {
		if(s[i] == '(') copen++;
		else copen--;
		if(copen < 0 or (i < n-1 and copen == 0)) {
			cout << ":(" << endl;
			return 0;
		}
		
	}
	if(copen != 0) {
		cout << ":(" << endl;
		return 0;
	}
	cout << s << endl;
}

