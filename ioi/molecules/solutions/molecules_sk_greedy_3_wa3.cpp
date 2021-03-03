/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

// idea : answer is a segment of sorted weights of length ceil(k0)
// time = O(n)

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (a); i <= (b); i++)
#  define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef pair <int, int> pii;
typedef long long ll;

// return value: result if solution exists and empty vector otherwise
vector<int> find_subset( int L, int U, vector<int> w ) {
	int n = w.size();
	double all = 0;
	vector<pii> wp(n);
	forn(i, n)
		wp[i] = pii(w[i], i), all += w[i];
	all /= n;
	sort(wp.begin(), wp.end());
	int k = ceil(L / all - 1e-9);
	err("try k=%d\n", k);
	vector<ll> pref(n + 1);
	forn(i, n)
		pref[i + 1] = pref[i] + wp[i].first;
	forn(l, n - k + 1) {
		ll sum = pref[l + k] - pref[l];
		if (L <= sum && sum <= U) {
			vector<int> res;
			forn(i, k)
				res.push_back(wp[l + i].second);
			return res;
		}			
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
