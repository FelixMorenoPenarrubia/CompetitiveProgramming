#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int MAX_B = 30;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("sorting.in", "r", stdin);

	int n;
	cin >> n;

	vi a(n);
	vi used(n, 0);
	vector<deque<int> > v(MAX_B);
	for(int i=0; i < n; ++i) {
		cin >> a[i];
		if(i > 0) {
			for(int j=0; j < MAX_B; ++j) {
				if((1<<j)&a[i]) {
					v[j].push_back(i);
				}
			}
		}
	}

	vi ans;
	vi st;

	vi visited(n, 0);
	for(int i=n-1; i > -1; --i) {
		st.push_back(i);
	}
	
	while(!st.empty()) {
		int i = st.back();
		st.pop_back();

		if(!visited[i]) {
			ans.push_back(a[i]);
			visited[i] = 1;
			used[i] = 1;
		}

		//cerr << "i = " << i << endl;

		int mnj = -1;
		int mn = -1;
		for(int j=0; j < MAX_B; ++j) {
			while(!v[j].empty() && used[v[j][0]]) v[j].pop_front();
			if((1<<j)&a[i] && !v[j].empty()) {
				if(mnj == -1 || v[j][0] < mn) {
					mn = v[j][0];
					mnj = j;
				}
			} 
		}
		if(mnj > -1) {
			st.push_back(i);
			st.push_back(mn);
			v[mnj].pop_front();
			//used[mn] = 1;
			
		}
	}

	for(int i=0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;


}