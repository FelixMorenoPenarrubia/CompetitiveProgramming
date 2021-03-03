/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

// should pass only group 1, group 2
// decreasing order

#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

typedef pair<int, int> pii;
typedef long long ll;

// return value: result if solution exists and empty vector otherwise
vector<int> find_subset( int l, int u, vector<int> w ) {
	int n = w.size();
	vector<pii> wp(n);
	vector<int> result(n);
	forn(i, n)
		wp[i] = pii(w[i], i);
	sort(all(wp));
	reverse(all(wp));
	function<int(int, int, ll, ll)> go = [&]( int i, int k, ll sum, ll rest ) {
		static int cnt = 0;
		cnt++;
		if (sum + rest < l || u < sum)
			return -1;
		//printf("i = %d(%d), k = %d, sum = %lld, rest = %lld\n", i, n, k, sum, rest);
		if (i == n) {
			fprintf(stderr, "cnt = %d\n", cnt);
			return k;
		}
		int tmp, x = wp[i].first;
		result[k] = wp[i].second;
		if ((tmp = go(i + 1, k + 1, sum + x, rest - x)) != -1)
			return tmp;
		while (i < n && wp[i].first == x)
			rest -= x, i++;
		return go(i, k, sum, rest);
	};
	int k = go(0, 0, 0, accumulate(all(w), 0LL));
	if (k == -1)
		return vector<int>();
	result.resize(k);
	return result;
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
