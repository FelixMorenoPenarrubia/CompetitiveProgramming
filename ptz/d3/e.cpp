#include<bits/stdc++.h>

using namespace std;


typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

struct pt {
	int x, y;
	char c;
	bool operator<(pt p) {
		if(x == p.x) return y < p.y;
		return x < p.x;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<pt> p(n);
	for(int i=0; i < n; ++i) {
		cin >> p[i].x >> p[i].y >> p[i].c;
		p[i].x *= 2;
		p[i].y *= 2;
		p[i].x += p[i].y/2;
		p[i].y -= p[i].x;
	}
	sort(p.begin(), p.end());

	vector<pt> phull;
	for(int i=0; i < n; ++i) {
		if(p[i].c == 'P') {
			while(!phull.empty() && phull.back().y <= p[i].y) phull.pop_back();
			phull.push_back(p[i]);
		}
	}
	vector<pt> nhull;
	for(int i=n-1; i > -1; --i) {
		if(p[i].c == 'N') {
			while(!nhull.empty() && nhull.back().y >= p[i].y) nhull.pop_back();
			nhull.push_back(p[i]);
		}
	}
	int pm = phull.size();
	int nm = nhull.size();
	int pj = -1;
	int nj = nm;

	int maxy = 1e9;

	vii intervals;
	for(int i=0; i < n; ++i) {

		while(pj < pm-1 && p[i].x >= phull[pj+1].x) { 
			pj++;

		}
		while(nj > 0 && p[i].x >= nhull[nj-1].x) { 
			nj--;
			maxy = nhull[nj].y;
		}


		if(p[i].c != 'N' && p[i].y < maxy) {
			int l = 0;
			int r = pj+1;
			while(r-l > 0) {
				int mid = (l+r)/2;
				if(phull[mid].y <= p[i].y) {
					r = mid;
				}
				else {
					l = mid+1;
				}
			}
			if(r < pj+1) intervals.emplace_back(l, pj);
		}
	}
	sort(intervals.begin(), intervals.end());

	int fu = 0;
	int maxr = -1;
	int ans = 0;
	for(int i=0; i < (int)intervals.size(); ++i) {
		if(intervals[i].first > fu) {
			if(intervals[i].first > maxr+1) {
				cout << "impossible" << endl;
				return 0;
			}
			fu = maxr+1;
			ans++;
		}
		if (intervals[i].second >= fu) {
			maxr = max(maxr, intervals[i].second);
		}
	}
	if(fu < pm) {
		if(maxr+1 < pm) {
			cout << "impossible" << endl;
			return 0;
		}
		ans++;
	}
	cout << ans << endl;
	
}