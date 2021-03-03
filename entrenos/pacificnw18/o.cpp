#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	int n;
	while(cin >>n) {
		vvi col(n, vi(n, 0));
		map<char, int> num;
		for(int i=0; i <= 9; ++i) {
			num['0'+i] = i;
		}
		for(int i=0; i < 26; ++i) {
			num['A'+i] = 10+i;
		}
		bool red = true;
		bool good = true;
		for(int i=0; i < n; ++i) {
			string s;
			cin >> s;
			vi row(n, 0);
			for(int j=0; j < n; ++j) {
				int c = num[s[j]];
				row[c] = 1;
				col[j][c] = 1;
				if(i == 0 && c != j) {
					red = false;
				}
				if(j == 0 && c != i) {
					red = false;
				}
			}
			for(int j=0; j < n; ++j) {
				if(!row[j]) {
					if(good) cout << "No" << endl;
					//return 0;
					good = false;
				}
			}
		}
		for(int i=0; i < n; ++i) {
			for(int j=0; j < n; ++j) {
				if(!col[i][j]) {
					if(good) cout << "No" << endl;
					//return 0;
					good = false;
				}
			}
		}
		if(good) cout << (red ? "Reduced" : "Not Reduced") << endl;
	}
}