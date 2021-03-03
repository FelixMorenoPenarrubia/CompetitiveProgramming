#include "molecules.h"
#include<algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

std::vector<int> find_subset(int l, int u, std::vector<int> w) {

	int n = w.size();
	vii v(n);
	for(int i=0; i < n; ++i) {
		v[i] = {w[i], i};
	}
	sort(v.begin(), v.end());

	int fi = 0;
	int cs = 0;
	vi ans;
	for(int i=0; i < n; ++i) {
		cs += v[i].first;
		while(cs > u) {
			cs -= v[fi].first;
			fi++;
		}
		if(cs >= l) {
			for(int j=fi; j <= i; ++j) {
				ans.push_back(v[j].second);
			}
			break;
		}

	}

    return ans;
}
