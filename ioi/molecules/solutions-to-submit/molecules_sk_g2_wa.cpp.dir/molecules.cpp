// name = molecules_sk_g2_wa.cpp, type = cpp.g++11

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


