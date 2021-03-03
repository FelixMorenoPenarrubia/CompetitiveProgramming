#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		int N = 6*n;
		vvi al(6*n, vi());
		vi indeg(6*n, 0);
		vi wc(6*n, 0);
		vi lc(6*n, 0);
		vi st(6*n, -1);
		vi typ(6);
		vi act(6);
		for(int i=0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			for(int j=0; j < 6; ++j) {
				int k = (j+1)%6;
				al[k*n+v].push_back(j*n+u);

				//cerr << "j = " << j << " u = " << u << " n = " << n << " indeg.size() " << indeg.size() << endl;
				indeg[j*n+u]++;
			}
		}

		string teams;
		cin >> teams;
		string acts;
		cin >> acts;



		for(int i=0; i < 6; ++i) act[i] = acts[i] == '1';

		for(int i=0; i < 6; ++i) {
			int j = (i+1)%6;
			typ[i] = (act[i] ^ act[j] ^ (teams[i] == teams[j]));
		}

		queue<int> q;
		for(int i=0; i < N; ++i) {
			if(indeg[i] == 0) {
				q.push(i);
				st[i] = act[i/n];

			}
		}

		while(!q.empty()) {
			int v = q.front();
			q.pop();
			for(int i=0; i < (int)al[v].size(); ++i) {
				int u = al[v][i];
				indeg[u]--;
				if(st[v]) wc[u]++;
				else lc[u]++;
				if(st[u] == -1) {
					if((typ[u/n] && wc[u] > 0) || (!typ[u/n] && lc[u] > 0)) {
						q.push(u);
						st[u] = 1;
					}
					else if(indeg[u] == 0) {
						q.push(u);
						st[u] = 0;
					}
				}
			}
		}

		string ans = string(n, '-');

		char t0 = teams[0];
		char t1 = (t0 == 'A') ? 'B' : 'A';
		if(act[0]) swap(t0, t1);
		for(int i=0; i < n; ++i) {
			if(st[i] == 1) ans[i] = t0;
			else if(st[i] == 0) ans[i] = t1;
			else ans[i] = 'D'; 
		}
		cout << ans << '\n';



		
	}
}