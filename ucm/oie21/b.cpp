#include<bits/stdc++.h>

using namespace std;

int main() {
	string s;

	while(cin >> s) {
		
		int n = s.length();
		for(int i=0; i < n-2; ++i) {
			if(s[i] != '.' && s[i+1] == '.' && s[i+2] == '.') {
				cout << s[i];
			}
		}
		cout << "\n";
	}
}