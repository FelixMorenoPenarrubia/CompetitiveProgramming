#include<bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int n = s.length();
	int k;
	cin >> k;

	string t = string(k, '-');
	int ci = -1;

	for(int i=0; i < n; ++i) {
		while(ci > -1 && k-ci <= n-i &&  t[ci] > s[i]) ci--;
		if(ci < k-1) {
			ci++;
			t[ci] = s[i];
		}
	}
	cout << t << endl;
}