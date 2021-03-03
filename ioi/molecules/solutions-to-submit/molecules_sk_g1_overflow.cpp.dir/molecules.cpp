// name = molecules_sk_g1_overflow.cpp, type = cpp.g++11

#include "molecules.h"
/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

// return value: result if solution exists and empty vector otherwise
vector<int> find_subset( int l, int u, vector<int> w ) {
	int n = w.size();
	int x = w[0], k = (l + x - 1) / x; // mistake!
	if (k > n || k * x > u) // mistake!
		return vector<int>();
	vector<int> result(k);
	forn(i, k)
		result[i] = i;
	return result;
}


