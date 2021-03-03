/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef pair <int, int> pii;
typedef long long ll;

// return value: result if solution exists and empty vector otherwise
vector<int> find_subset( int l, int u, vector<int> w ) {
	int n = w.size();
	vector<pii> wp(n);
	forn(i, n)
		wp[i] = pii(w[i], i);
	sort(wp.begin(), wp.end());
	vector<ll> mi(n + 1), ma(n + 1);
	forn(i, n) {
		mi[i + 1] = mi[i] + wp[i].first;
		ma[i + 1] = ma[i] + wp[n - i - 1].first;
	}
	forn(i, n + 1)
		if (mi[i] <= u && ma[i] >= l) {
			int pos = n - 1;
			ll sum = mi[i];
			vector<int> result(i);
			forn(j, i) {
				while (pos >= i && sum + wp[pos].first - wp[j].first > u)
					pos--;
				if (pos >= i && sum + wp[pos].first - wp[j].first <= u)
					sum += wp[pos].first - wp[j].first, result[j] = wp[pos--].second;
				else
					result[j] = wp[j].second;
			}
			return result;
		}
	return vector<int>();
}

// BEGIN CUT

int main() {
    int n, l, u;
    scanf("%d %d %d", &n, &l, &u);
    std::vector<int> w(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    std::vector<int> result = find_subset(l, u, w);
    
    // BEGIN SECRET
    puts("14e047d7a2907b9034950b074822b302");
    // END SECRET
    
    printf("%d\n", (int)result.size());
    for (int x : result)
        printf("%d ", x);
    printf("\n");
}

// END CUT
