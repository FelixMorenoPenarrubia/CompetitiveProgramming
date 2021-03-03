// name = molecules_sk_g3_dp.cpp, type = cpp.g++11

#include "molecules.h"
/** Author: Sergey Kopeliovich (Burunduk30@gmail.com) */

// time = O(u*n), space = O(u*n)

#include <cstdio>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

// return value: result if solution exists and empty vector otherwise
vector<int> find_subset( int l, int u, vector<int> w ) {
	int n = w.size(), t;
	vector<vector<int>> p(n + 1, vector<int>(u + 1, -1));
	p[0][0] = 0;
	forn(k, n)
		forn(j, u + 1)
			if (p[k][j] != -1) {
				//printf("k = %d, j = %d\n", k, j);
				p[k + 1][j] = 0;
				if (j + w[k] > u) 
					continue;
				t = j + w[k];
				p[k + 1][t] = 1;
			}
	for (int j = l; j <= u; j++)
		if (p[n][j] != -1) {
			vector<int> res;
			while (n--)
				if (p[n + 1][j])
					res.push_back(n), j -= w[n];
			return res;
		}
	return vector<int>();
}


