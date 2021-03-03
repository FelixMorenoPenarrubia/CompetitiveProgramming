#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int n = s.length();
	ll ans = 0;
	vi occ(27, 0);

	/*for(int i=0; i < n; ++i) {
		occ[s[i]-'a']++;
	}*/

	//char lc = '-';

	for(int i=n-1; i > -1; --i) {
		if(s[i] == s[i+1]) {
			ans += n-i-occ[s[i]-'a']-1;
			for(char c = 'a'; c <= 'z'; ++c) {
				if(c != s[i]) occ[c-'a'] = 0;
			}
			occ[s[i]-'a'] = n-i;
		}
		else occ[s[i]-'a']++;
	}

	cout << ans << endl;

}