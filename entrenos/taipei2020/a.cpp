#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	while(N--) {
		int x;
		cin >> x;
		bool b = true;
		for(int i=1; i*i <= x; ++i) {
			if(x%i == 0) {
				int j = x/i;
				if(2*i >= j) {
					cout << "1\n";
					b = false;
					break;
				}
			}
		}
		if(b) cout << "0\n";
	}
}