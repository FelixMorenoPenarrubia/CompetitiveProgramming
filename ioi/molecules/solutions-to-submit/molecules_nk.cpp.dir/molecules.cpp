// name = molecules_nk.cpp, type = cpp.g++11

#include "molecules.h"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

int n;
vector<pair<int, int>> a;

std::vector<int> find_subset( int L, int U, std::vector<int> w )
{
	n = w.size();
	for (int i = 0; i < n; i++) a.pb({w[i], i});
	sort(all(a));
	ll sum = 0;
	int k = 0;
	while (k < n && sum < L)
	{
		sum += a[k].fi;
		k++;
	}
	vector<int> answer;
	if (L <= sum && sum <= U)
	{
		for (int i = 0; i < k; i++) answer.pb(a[i].se);
		return answer;
	}
	if (sum < L) return answer;
	// sum > U
	k--;
	sum -= a[k].fi;
	for (int i = k - 1; i >= 0; i--)
	{
		int now = n - 1 - (k - 1 - i);
		sum += a[now].fi - a[i].fi;
		if (L <= sum && sum <= U)
		{
			for (int j = 0; j < i; j++) answer.pb(a[j].se);
			for (int j = now; j < n; j++) answer.pb(a[j].se);
			return answer;
		}
	}
	return answer;
}

#define forn(i, n) for (int i = 0; i < (int)(n); i++)


