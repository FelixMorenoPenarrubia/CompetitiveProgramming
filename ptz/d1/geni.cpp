#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX_VAL = 1e6;

vvi divisors;

void sieve() {
	divisors = vvi(MAX_VAL+1, vi(1, 1));

	for(int i=2; i <= MAX_VAL; ++i) {
		for(int j=1; j*i <= MAX_VAL; ++j) {
			divisors[i*j].push_back(i);
		}
	}

}

inline int gcd(int x, int y) {
	while(y) x %= y, swap(x, y);
	return x;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 20;
	cout << T << endl;
	while(T--) {
		cout << 2*MAX_VAL << endl;
		for(int i=1; i <= MAX_VAL; ++i) {
			cout << i << " " << i << " ";
		}
		cout << endl;
	}

	
}