#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi sumdiv;

void sieve() {
	const int MAX= 3e5;

	vi numdiv(MAX+1);
	sumdiv = vi(MAX+1);

	for(int i=1; i < MAX; ++i) {
		for(int j=1; j*i < MAX; ++j) {
			numdiv[j*i]++;
		}
	}
	for(int i=1; i < MAX; ++i) {
		sumdiv[i] = sumdiv[i-1] + numdiv[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();
	int k;
	cin >> k;
	long long ans = 0;
	for(int a=1; a <= k; ++a) {
		ans += sumdiv[k/a];
	}
	cout << ans << endl;
}