//#define _GLIBCXX_DEBUG

/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

// time = O(u*n/word_size), space = O(u)

#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef pair <int, int> pii;
typedef long long ll;

const int MAX_U = 3e5 + 10;

// return value: result if solution exists and empty vector otherwise
vector<int> find_subset( int l, int u, vector<int> w ) {
	int n = w.size();
	vector<int> p(u + 33, -1);
	assert(u <= MAX_U);
	bitset<MAX_U> was;
	was[0] = 1;
	forn(k, n) {
		bitset<MAX_U> to_change = (was << w[k])	& ~was;
		was |= to_change;
		unsigned int *data = (unsigned int *)&to_change;
		forn(i, (u / 32) + 1)
			if (data[i])
				forn(j, 32)
					if ((data[i] >> j) & 1) {
						int t = i * 32 + j;
						p[t] = k;
						if (l <= t && t <= u) {
							vector<int> res;
							while (t) {
								int i = p[t];
								t -= w[i];
								res.push_back(i);
							}
							return res;
						}					
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
