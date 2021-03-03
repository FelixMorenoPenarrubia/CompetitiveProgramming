#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	vi v(n);
	for(int i=0; i< n; ++i) {
		cin>> v[i];
		
	}
	sort(v.begin(), v.end());
	int t = v[n/2];
	int ans = 0;
	for(int i=0; i < n; ++i) {
		if(v[i] < t-1) {
			ans += t-1-v[i];
		}
		else if(v[i] > t+1) {
			ans += v[i]-t-1;
		}
	}
	cout << t << " " << ans << endl;
}
