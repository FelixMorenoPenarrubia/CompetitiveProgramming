#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--) {
		int n, h, H;
		cin >> n >> h >> H;
		vi x(n);
		for(int i=0; i < n; ++i) cin >> x[i];
		vi c(n);
		for(int i=0; i < n; ++i) cin >> c[i];

		int mini = 0;
		int minans = 1e9;

		for(int i=0; i < n; ++i) {
			if(x[i]%(2*H) > h && x[i]%(2*H) < 2*H-h) {
				x[i] += (2*H-h-(x[i]%(2*H)));
			}
			if(x[i] + c[i] < minans) {
				mini = i;
				minans = x[i]+c[i];
			}
		}
		cout << mini+1 << endl;
	}
}