#include<bits/stdc++.h>

using namespace std;


int main() {
	string s, t;
	while(cin >> s >> t) {
		string v = t + '#' + s + s;
		int n = v.size();
		vector<int> p(n, 0);
		int ans = 0;
		for(int i=1; i < n-1; ++i) {

			int j = i-1;
			while(j >= 0 and v[p[j]] != v[i]) {
				j = p[j]-1;
			}
			if(j >= 0) p[i] = p[j]+1;
			else p[i] = 0;

			if(p[i] == t.size()) ans++;
			
		}
		cout << ans << endl;
	}
}