// name = molecules_sk_bruteforce_2.cpp, type = cpp.g++11

#include "molecules.h"
/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

// should pass only group 1
// increasing order

#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

typedef pair<int, int> pii;
typedef long long ll;

// return value: result if solution exists and empty vector otherwise
vector<int> find_subset( int l, int u, vector<int> w ) {
	int n = w.size();
	vector<pii> wp(n);
	vector<int> result(n);
	forn(i, n)
		wp[i] = pii(w[i], i);
	sort(all(wp));
	function<int(int, int, ll, ll)> go = [&]( int i, int k, ll sum, ll rest ) {
		static int cnt = 0;
		cnt++;
		if (sum + rest < l || u < sum)
			return -1;
		if (i == n) {
			fprintf(stderr, "cnt = %d\n", cnt);
			return k;
		}
		int tmp, x = wp[i].first;
		result[k] = wp[i].second;
		if ((tmp = go(i + 1, k + 1, sum + x, rest - x)) != -1)
			return tmp;
		//while (i < n && wp[i].first == x)
		//	rest -= x, i++;
		return go(i + 1, k, sum, rest - x);
	};
	int k = go(0, 0, 0, accumulate(all(w), 0LL));
	if (k == -1)
		return vector<int>();
	result.resize(k);
	return result;
}


