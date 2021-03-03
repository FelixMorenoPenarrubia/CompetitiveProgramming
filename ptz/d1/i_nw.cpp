#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX_VAL = 1e6+5;

vvi divisors;
vvi pf;

void sieve() {
	divisors = vvi(MAX_VAL+1, vi(1, 1));
	pf = vvi(MAX_VAL+1);

	for(int i=2; i <= MAX_VAL; ++i) {
		bool ispr = (divisors[i].size() == 1);
		for(int j=1; j*i <= MAX_VAL; ++j) {
			divisors[i*j].push_back(i);
			if(ispr) pf[i*j].push_back(i);
		}
	}

}


bool coprime(int x, int y) {
	int i = 0;
	int j = 0;
	while(i < (int)pf[x].size() && j < (int)pf[y].size()) {
		if(pf[x][i] < pf[y][j]) {
			i++;
		}
		else if(pf[x][i] > pf[y][j]) {
			j++;
		}
		else return false;
	}
	return true;
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

				if(0 <= aj && aj <= MAX_VAL && freq[aj] > 0 && aj % divisors[a[i]][j] == 0 && coprime(a[i]/divisors[a[i]][j], aj/divisors[a[i]][j])) {
					ans += ((ll)freq[a[i]])*((ll)freq[aj]);
				}
			}
			visit[a[i]] = 1;
		}

		cout << ans/2 << '\n';

	}
}