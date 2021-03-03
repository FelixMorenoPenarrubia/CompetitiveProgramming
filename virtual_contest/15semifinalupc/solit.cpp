#include<bits/stdc++.h>

using namespace std;


typedef pair<int, int> ii;
typedef vector<ii> vii;


int iterate(const vii &v) {
	int n = v.size();
	for(int i=0; i < n-2; ++i) {
		if(v[i].first == v[i+2].first or v[i].second == v[i+2].second) return i;
	}
	return -1;
}

int main() {

	vii v;
	for(int i=0; i < 12; ++i) {
		for(int j=0; j < 4; ++j) {
			v.emplace_back(i, j);
		}
	}
	srand(time(NULL));

	int T;
	cin >> T;
	int win = 0;
	for(int t=0; t < T; ++t) {
		random_shuffle(v.begin(), v.end());
		vii w = vii(v);
		int idx;
		while(true) {
			idx = iterate(w);
			if(idx == -1) break;
			vii neww;
			for(int i=0; i < (int)w.size(); ++i) {
				if(i == idx) continue;
				neww.push_back(w[i]);
			}
			w = neww;
		}
		win += ((int)w.size() == 2);

	}

	cout << double(win)/double(T) << endl;

}