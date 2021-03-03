/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

// idea : answer is a prefix + a suffix of NOT sorted weights
// time = O(n)

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef pair <int, int> pii;
typedef long long ll;

// return value: result if solution exists and empty vector otherwise
vector<int> find_subset( int L, int U, vector<int> w ) {
	int n = w.size();
	vector<pii> wp(n);
	ll sum = 0;
	forn(i, n)
		wp[i] = pii(w[i], i), sum += w[i];
	
	forn(_, 10) {
		int r = n;
		for (int l = n; l >= 0; l--) {
			while (r > l && sum < L)
				sum += wp[--r].first;
			if (L <= sum && sum <= U) {
				vector<int> res;
				while (l--)
					res.push_back(wp[l].second);
				while (r < n)
					res.push_back(wp[r++].second);
				return res;
			}			
			if (l)
				sum -= wp[l - 1].first;
		}
		random_shuffle(wp.begin(), wp.end());
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
