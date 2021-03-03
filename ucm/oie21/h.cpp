#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
	
	int T;
	cin >> T;
	while(T--) {
		int x;
		cin >> x;
		if(x <= 2) {
			cout << x << "\n";
			continue;
		}
		int a = 1;
		int b = 1;
		int t = 2;
		for(int i=0; i < 100; ++i) {
			int c = b+2*a;
			t += c;
			if(t >= x) {
				cout << i+3 << "\n";
				break;
			}
			a = b;
			b = c;
		}
	}
}