#include<bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("equal.in", "r", stdin);

	int T;
	cin >> T;
	while(T--) {
		int a, b, c;
		cin >> a >> b >> c;
		if(a == b || b == c || c == a) cout << "YES\n";
		else cout << "NO\n";
	}
}