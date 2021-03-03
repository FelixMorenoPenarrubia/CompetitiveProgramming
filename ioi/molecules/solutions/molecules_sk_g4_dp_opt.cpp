/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

// time = O(u*n), space = O(u)

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

typedef pair <int, int> pii;
typedef long long ll;

// return value: result if solution exists and empty vector otherwise
vector<int> find_subset( int l, int u, vector<int> w ) {
	int n = w.size(), t;
	vector<int> p(u + 1, -1);
	p[0] = 0;
	int sum = 0;
	forn(k, n) {
		for (int j = min(sum, min(l - 1, u - w[k])); j >= 0; j--)
			if (p[j] != -1 && p[t = j + w[k]] == -1) {
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
		sum = min((ll)l, (ll)sum + w[k]);
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
