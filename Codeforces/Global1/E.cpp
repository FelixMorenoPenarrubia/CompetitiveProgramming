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
	vi s (n);
	vi t (n);
	for(int i=0; i < n; i++) cin >> s[i];
	for(int i=0; i < n; i++) cin >> t[i];
	if(s[0] != t[0] or s[n-1] != t[n-1]) {
		cout << "No" << endl;
		return 0;
	}
	map<ll, ll> a;
	map<ll, ll> b;
	for(int i=0; i < n-1; i++) a[s[i+1]-s[i]]++;
	for(int i=0; i < n-1; i++) b[t[i+1]-t[i]]++;
	bool good = true;
	for(auto it = a.begin(); it != a.end(); it++) {
		if(a[it->first] != b[it->first]) good = false;
	}
	for(auto it = b.begin(); it != b.end(); it++) {
		if(a[it->first] != b[it->first]) good = false;
	}
	if(good) cout << "Yes" << endl;
	else cout << "No" << endl;
	
}
