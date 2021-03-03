#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


void NO() {
	cout << "N" << endl;
	exit(0);
}

int main() {
	int n;
	cin >> n;

	vvi grid(10, vi(10, 0));

	for(int i=0; i < n; ++i) {
		int d, l, r, c;
		cin >> d >> l >> r >> c;
		r--;
		c--;
		if(d == 0) {
			for(int j=0; j < l; ++j) {
				if(c > 9 || grid[r][c]) {
					NO();
				}
				grid[r][c] = 1;
				c++;
			}
		}
		else {
			for(int j=0; j < l; ++j) {
				if(r > 9 || grid[r][c]) {
					NO();
				}
				grid[r][c] = 1;
				r++;
			}
		}
	}
	cout << "Y" << endl;

}