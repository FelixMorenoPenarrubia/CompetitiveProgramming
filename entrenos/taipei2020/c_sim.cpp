#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	int n, k;
	cin >> n >> k;
	vvi a(n, vi(n, 0));
	for(int t=1; t <= k; ++t) {
		int x = 0;
		int y = 0;
		vvi pt(n, vi(n, 0));

		for(int i=0; i < n-1; ++i) {
			pt[x][y] = 1;
			a[x][y] = !a[x][y];
			if(a[x][y]) {
				x++;
			}
			else {
				y++;
			}
		}
		pt[x][y] = 1;
		/*for(int i=0; i < n; ++i) {
			for(int j=0; j < n; ++j) {
				if(pt[j][n-1-i]) cout << "O";
				else cout << (a[j][n-1-i] ? "X" : ".");
			}
			cout << endl;
		}*/
		cout << y << " ";
	}
	cout << endl;

}