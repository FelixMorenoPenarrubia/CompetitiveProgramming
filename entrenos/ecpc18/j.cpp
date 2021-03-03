#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;



int main() {


	freopen("unique.in", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int x = n/2;
		vi obtv = vi(n);
		string s = "0";
		for(int i=0; i < n-1; ++i) {
			if(x%2) {
				s.push_back('1');
				x = (x-1)/2;
			}
			else {
				s.push_back('0');
				x = x/2;
			}
			if(!obtv[x+n/2]) {
				x += n/2;
				obtv[x] = 1;
			}
			else {
				obtv[x] = 1;
			}
		}
		reverse(s.begin(), s.end());
		cout << s << "\n";

	}


}