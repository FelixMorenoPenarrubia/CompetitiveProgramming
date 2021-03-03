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
vector<int> find_subset( int l, int u, const vector<int> &_w ) {
	int n = _w.size();
	vector<pii> wp(n);
	forn(i, n)
		wp[i] = pii(_w[i], i);
	sort(all(wp));
	forn(t, 2) {
		ll sum = 0;
		forn(i, n) {
			sum += wp[i].first;
			if (l <= sum && sum <= u) {
				vector<int> result(i + 1);
				forn(j, i + 1)
					result[j] = wp[j].second;
				return result;
			}
		}
		reverse(all(wp));
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
