#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
	int n, m;

	while(cin >> n >> m) {
		
		
		vi v(100);
		vi u(101);
		for(int i=0; i < n; ++i) {
			int x;
			cin >> x;
			x--;
			v[x]++;
		}
		for(int i=0; i < m; ++i) {
			int x;
			cin >> x;
			x--;
			u[x]++;
		}
		int ans = 0;
		for(int i=0; i < 100; ++i) {
			int d = min(v[i], u[i]);
			v[i] -= d;
			u[i] -= d;
			if(v[i] > 0) {
				int e = min(v[i], u[i+1]);
				v[i] -= e;
				u[i+1] -= e;
				ans += v[i];
			}
		}
		cout << ans << "\n";
	}
}