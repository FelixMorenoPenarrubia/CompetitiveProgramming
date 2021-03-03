// name = molecules_sk_g4_dp_slow.cpp, type = cpp.g++11

#include "molecules.h"
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
	forn(k, n)
		for (int j = min(l - 1, u - w[k]); j >= 0; j--)
			if (p[j] != -1 && p[t = j + w[k]] == -1)
				p[t] = k;
	for (int t = l; t <= u; t++)
		if (p[t] != -1) {
			vector<int> res;
			while (t) {
				int i = p[t];
				t -= w[i];
				res.push_back(i);
			}
			return res;
		}					
	return vector<int>();
}


