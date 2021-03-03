#include<bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<int> f(1e5);
		for(int i=0; i < n; ++i) {
			string s;
			cin >> s;
			int m;
			cin >> m;
			f[m]++;
		}
		int maxi = 0;
		int maxf = 0;
		for(int i=0; i < 1e5; ++i ) {
			if(f[i] > maxf) {
				maxi = i;
				maxf = f[i];
			}
		}
		cout << maxi << endl;
	}

}