#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		vi c;
		int ans = 0;
		for(int i=0; i < n; ++i) {
			int x;
			cin >> x;
			while(!c.empty() && x < c.back()) {
				c.pop_back();
				ans++;
			}
			c.push_back(x);
 		}
 		cout << ans << "\n";
		
	}
}