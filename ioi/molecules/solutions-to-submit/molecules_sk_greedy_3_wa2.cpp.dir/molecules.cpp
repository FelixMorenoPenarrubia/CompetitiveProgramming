// name = molecules_sk_greedy_3_wa2.cpp, type = cpp.g++11

#include "molecules.h"
/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

// idea : answer is a segment of sorted weights of length round(k0)
// time = O(n)

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (a); i <= (b); i++)
#  define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef pair <int, int> pii;
typedef long long ll;

// return value: result if solution exists and empty vector otherwise
vector<int> find_subset( int L, int U, vector<int> w ) {
	int n = w.size();
	double all = 0;
	vector<pii> wp(n);
	forn(i, n)
		wp[i] = pii(w[i], i), all += w[i];
	all /= n;
	sort(wp.begin(), wp.end());
	int k = round(((double)L + U) / 2 / all);
	err("try k=%d\n", k);
	vector<ll> pref(n + 1);
	forn(i, n)
		pref[i + 1] = pref[i] + wp[i].first;
	forn(l, n - k + 1) {
		ll sum = pref[l + k] - pref[l];
		if (L <= sum && sum <= U) {
			vector<int> res;
			forn(i, k)
				res.push_back(wp[l + i].second);
			return res;
		}			
	}
	return vector<int>();
}


