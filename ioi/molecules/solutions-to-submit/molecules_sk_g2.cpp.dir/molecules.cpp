// name = molecules_sk_g2.cpp, type = cpp.g++11

#include "molecules.h"
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


