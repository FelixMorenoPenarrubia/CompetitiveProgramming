// name = molecules_sk_greedy_3_ok.cpp, type = cpp.g++11

#include "molecules.h"
/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

// idea : answer is a segment of sorted weights of length in floor(k0)..ceil(k0)
// time = O(n)

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (a); i <= (b); i++)

typedef pair <int, int> pii;
typedef long long ll;

// return value: result if solution exists and empty vector otherwise
vector<int> find_subset( int L, int U, vector<int> w ) {
	int n = w.size();
	vector<pii> wp(n);
	forn(i, n)
		wp[i] = pii(w[i], i);
	sort(wp.begin(), wp.end());
	double k0 = L / (accumulate(w.begin(), w.end(), 0.0) / n);
	vector<ll> pref(n + 1);
	forn(i, n)
		pref[i + 1] = pref[i] + wp[i].first;
	forab(k, (int)floor(k0), (int)ceil(k0))
		if (1 <= k && k <= n)
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


