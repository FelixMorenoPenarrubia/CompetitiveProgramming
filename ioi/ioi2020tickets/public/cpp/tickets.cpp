#include "tickets.h"
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

long long find_maximum(int k, std::vector<std::vector<int>> x) {
	int n = x.size();
	int m = x[0].size();
	ll ansv = 0;


	vi curidx = vi(n, 0);

	set<ii> curmin;
	for(int i=0; i < n; ++i) {
		curmin.insert(ii(x[i][0] + x[i][m-k], i));
		for(int j=m-k; j < m; ++j) {
			ansv += x[i][j];
		}
	}

	for(int z=0; z < (n/2)*k; ++z) {
		ii p = *(curmin.begin());
		curmin.erase(curmin.begin());
		ansv -= p.first;
		int i = p.second;
		curidx[i]++;
		if(curidx[i]+m-k < m) {
			curmin.insert(ii(x[i][curidx[i]] + x[i][curidx[i]+m-k], i));
		}
	}

	vvi answer = vvi(n, vi(m, -1));
	vi cnt = vi(curidx);
	vi pi = vi(n, m-1);
	vi ni = vi(n, 0);
	for(int z=0; z < k; ++z) {
		vector<ii> sv (n);
		for(int i=0; i < n; ++i) sv[i] = ii(cnt[i], i);
		sort(sv.begin(), sv.end());
		for(int j=0; j < n; ++j) {
			int i = sv[j].second;
			if(j < n/2) {
				answer[i][pi[i]] = z;
				pi[i]--;
			}
			else {
				answer[i][ni[i]] = z;
				ni[i]++;
				cnt[i]--;
			}
		}
	}

	allocate_tickets(answer);


	return ansv;
}
