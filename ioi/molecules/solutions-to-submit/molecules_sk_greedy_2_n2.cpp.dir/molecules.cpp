// name = molecules_sk_greedy_2_n2.cpp, type = cpp.g++11

#include "molecules.h"
/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

// idea : answer is a prefix + a suffix of sorted weights
// time = O(n^2)

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
	forn(i, n)
		wp[i] = pii(w[i], i);
	sort(wp.begin(), wp.end());
	forn(l, n) {
		ll sum = 0;
		forn(i, l)
			sum += wp[i].first;
		for (int r = n; r >= l; r--) {
			if (L <= sum && sum <= U) {
				vector<int> res;
				while (l--)
					res.push_back(wp[l].second);
				while (r < n)
					res.push_back(wp[r++].second);
				return res;
			}			
			if (r > l)
				sum += wp[r - 1].first;
		}
	}
	return vector<int>();
}


