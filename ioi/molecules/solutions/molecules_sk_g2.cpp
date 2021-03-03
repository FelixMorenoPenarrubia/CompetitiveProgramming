/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

typedef pair <int, int> pii;
typedef long long ll;

// return value: result if solution exists and empty vector otherwise
vector<int> find_subset( int l, int u, vector<int> _w ) {
	int n = _w.size();
	vector<pii> wp(n);
	forn(i, n)
		wp[i] = pii(_w[i], i);
	sort(all(wp));
	int k = 0, x = wp[0].first;
	while (k < n && x == wp[k].first)
		k++;
	forn(i, k + 1) 
		forn(j, n - k + 1) {
			ll sum = (ll)x * i + (ll)(x + 1) * j;
			if (l <= sum && sum <= u) {
				vector<int> result(i + j);
				forn(t, i)
					result[t] = wp[t].second;
				forn(t, j)
					result[i + t] = wp[n - 1 - t].second;
				return result;
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
