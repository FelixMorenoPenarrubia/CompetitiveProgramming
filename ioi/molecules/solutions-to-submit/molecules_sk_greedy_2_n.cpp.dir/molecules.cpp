// name = molecules_sk_greedy_2_n.cpp, type = cpp.g++11

#include "molecules.h"
/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

// idea : answer is a prefix + a suffix of sorted weights
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
	ll sum = 0;
	forn(i, n)
		wp[i] = pii(w[i], i), sum += w[i];
	sort(wp.begin(), wp.end());
	
	int r = n;
	for (int l = n; l >= 0; l--) {
		while (r > l && sum < L)
			sum += wp[--r].first;
		if (L <= sum && sum <= U) {
			vector<int> res;
			while (l--)
				res.push_back(wp[l].second);
			while (r < n)
				res.push_back(wp[r++].second);
			return res;
		}			
		if (l)
			sum -= wp[l - 1].first;
	}
	return vector<int>();
}


