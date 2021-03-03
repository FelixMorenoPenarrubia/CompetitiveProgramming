#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX_VAL = 1e6+5;

vvi divisors;
vector<unordered_set<int> > divset;

void sieve() {
	divisors = vvi(MAX_VAL+1, vi(1, 1));
	divset = vector<unordered_set<int> >(MAX_VAL+1);

	for(int i=2; i <= MAX_VAL; ++i) {
		for(int j=1; j*i <= MAX_VAL; ++j) {
			divisors[i*j].push_back(i);
			divset[i*j].insert(i);
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

	sieve();

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;

		vi a(n);
		vi freq(MAX_VAL+1);
		vi visit(MAX_VAL+1);
		for(int i=0; i < n; ++i) {
			cin >> a[i];
			freq[a[i]]++;
		}

		ll ans = 0;

		for(int i=0; i < n; ++i) {
			if(visit[a[i]]) continue;
			for(int j=0; j < (int)divisors[a[i]].size(); ++j) {
				int aj = divisors[a[i]][j]^a[i];
				int qr = a[i]/divisors[a[i]][j];
				if(0 <= aj && aj <= MAX_VAL && freq[aj] > 0 && aj % divisors[a[i]][j] == 0 
					&& divset[qr].find(aj/divisors[a[i]][j]) == divset[qr].end()) {
					ans += ((ll)freq[a[i]])*((ll)freq[aj]);
				}
			}
			visit[a[i]] = 1;
		}

		cout << ans/2 << endl;

	}
}