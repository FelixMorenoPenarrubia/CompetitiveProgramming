#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

bool finish = false;

int abx(int x) {
	return (x > 0) ? x : -x;
}


void baq(int idx, int n,  vi& p,  map<int, int>& dist) {
	if(finish) return;
	if(idx == n) {
		sort(p.begin(), p.end());
		for(int i=0; i < n; ++i) {
			cout << p[i] << " ";
		}
		cout << "\n";
		finish = true;
		return;
	}


	/*cerr << "baq(" << idx << ", " << n << "): " << endl;

	cerr << "pts" << endl;
	for(int i=0; i < idx; ++i) {
		cerr << p[i] << endl;
	}

	cerr << "dist: " << endl;
	for(auto x : dist) {
		cerr << x.first << " " << x.second << endl;
	}*/




	auto it = dist.end();
	it--;
	while(it->second == 0) it--;
	int md = it->first;
	if(p[1]-md >= 0) {
		bool good = true;
		int np = p[1]-md;
		//map<int, int> ndist = map<int, int>(dist);
		int ci = idx;
		for(int i=0; i < idx; ++i) {
			if(dist[abx(p[i]-np)] == 0) {
				good = false;
				ci = i;
				break;
			}
			else {
				dist[abx(p[i]-np)]--;
			}
		}
		if(good) {
			vi nvp = vi(p);
			nvp.push_back(np);
			baq(idx+1, n, nvp, dist);
		}
		for(int i=0; i < ci; ++i) {
		/*	if(dist[abx(p[i]-np)] == 0) {
				good = false;
				ci = i;
				break;
			}
			else {*/
				dist[abx(p[i]-np)]++;
		//	}
		}
	}
	{
		bool good = true;
		int np = md;
		//map<int, int> ndist = map<int, int>(dist);
		int ci = idx;
		for(int i=0; i < idx; ++i) {
			if(dist[abx(p[i]-np)] == 0) {
				good = false;
				ci = i;
				break;
			}
			else {
				dist[abx(p[i]-np)]--;
			}
		}
		if(good) {
			vi nvp = vi(p);
			nvp.push_back(np);
			baq(idx+1, n, nvp, dist);
		}
		for(int i=0; i < ci; ++i) {
		/*	if(dist[abx(p[i]-np)] == 0) {
				good = false;
				ci = i;
				break;
			}
			else {*/
				dist[abx(p[i]-np)]++;
		//	}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int m = (n*(n-1))/2;
		map<int, int> dist;
		for(int i=0; i < m; ++i) {
			int d;
			cin >> d;
			dist[d]++;
		}
		auto it = dist.end();
		it--;
		int md = it->first;
		dist[md]--;
		vi p = vi(2);
		p[0] = 0;
		p[1] = md;
		finish = false;
		baq(2, n, p, dist);

	}
}