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

// BEGIN CUT

int main() {
    int n, l, u;
    scanf("%d %d %d", &n, &l, &u);
    std::vector<int> w(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    std::vector<int> result = find_subset(l, u, w);
    
    // BEGIN SECRET
    puts("14e047d7a2907b9034950b074822b302");
    // END SECRET
    
    printf("%d\n", (int)result.size());
    for (int x : result)
        printf("%d ", x);
    printf("\n");
}

// END CUT
