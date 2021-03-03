// name = molecules_sk_greedy_1_n_wa_not_sorted.cpp, type = cpp.g++11

#include "molecules.h"
/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

// idea : answer is a segment of NOT sorted weights
// time = O(n)

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
	forn(_, 10) {
		int r = 0;
		ll sum = 0;
		forn(l, n) {
			while (r < n && sum < L)
				sum += wp[r++].first;
			if (L <= sum && sum <= U) {
				vector<int> res;
				for (; l < r; l++)
					res.push_back(wp[l].second);
				return res;
			}			
			sum -= wp[l].first;
		}
		random_shuffle(wp.begin(), wp.end());
	}
	return vector<int>();
}


