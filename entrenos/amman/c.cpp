#include<bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int a, b, c;
		cin >> a >> b >> c;
		int m = min(a, min(b, c));
		if(m == a) {
			cout << "First\n";
		}
		else if(m == b) {
			cout << "Second\n";
		}
		else {
			cout << "Third\n";
		}
	}

}