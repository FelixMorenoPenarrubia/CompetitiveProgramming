#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int ans = (2*n)/k;
	if((2*n)%k) ans++;
	if(n <= k) ans = 2;
	cout << ans << endl;	
}