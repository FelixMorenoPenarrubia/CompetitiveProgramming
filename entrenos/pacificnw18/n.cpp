#include<bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.length();
	for(int i=0; i < n; ++i) {
		for(int j=i+1; j < n; j+= 2) {
			bool pal = true;
			for(int k=0; k <= j-i; ++k) {
				if(s[i+k] != s[j-k] ) pal = false;
			}
			if(pal) {
				cout << "Or not." << endl;
				return 0;
			}
		}
	}
	cout << "Odd." << endl;
}