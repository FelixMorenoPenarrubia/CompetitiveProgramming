/** 
	Author: Sergey Kopeliovich (Burunduk30@gmail.com) 
	Random walk
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef pair <int, int> pii;

// return value: result if solution exists and empty vector otherwise
vector<int> find_subset( int l, int u, vector<int> w ) {
	int n = w.size();
	vector<pii> wp(n);
	forn(i, n)
		wp[i] = {w[i], i};
	mt19937 rnd(239);
	forn(_, 1000) {
		shuffle(wp.begin(), wp.end(), rnd);
		int sum = 0, i = 0;
		while (i < n && sum < l)
			sum += wp[i++].first;
		if (l <= sum && sum <= u) {
			vector<int> res(i);
			forn(j, i)
				res[j] = wp[j].second;
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
