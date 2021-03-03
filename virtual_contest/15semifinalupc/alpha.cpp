#include<bits/stdc++.h>

using namespace std;

int main() {
	string s;
	int k;
	while(cin >> s >> k) {
		int n = s.length();
		int idx = n-k;
		for(int i=0; i < n-k; ++i) {
			if(s[i] > s[i+k]) {
				idx = i;
				break;
			}
		}
		string t = s.substr(0, idx) + s.substr(idx+k, n-idx-k);
		cout << t << endl;
	}
}