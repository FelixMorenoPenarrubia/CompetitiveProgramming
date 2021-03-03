#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


int n, m;
vvi mp;
vii ans;
vvi al;
vi ap;
vi visited;
vi up;
vi depth;

void dfs(int v, int p, int d) {
	if(visited[v]) return;

	cerr << "visiting vertex " << v << endl;

	visited[v] = 1;
	up[v] = 0;
	depth[v] = d;
	int ori = 0;
	bool chd = false;
	for(int u : al[v]) {
		if(u == p) {

		}
		else if (!visited[u]) {
			chd = true;
			dfs(u, v, d+1);
			up[v] += up[u];
		}
		else {
			if(depth[u] < d) {
				up[v]++;
				ori++;
			}
			else {
				up[v]--;
			}
		}
	}
	if(chd && up[v] == ori) {

		cerr << "vertex " << v << " is ap " << endl;

		ap[v] = 1;
	}
}


void process_shift(int d) {

	cerr << "SHIFT " << d << endl;

	al = vvi(n*m+m, vi());
	up = vi(n*m+m, 0);
	depth = vi(n*m+m, 0);
	for(int id=d; id < n+d; ++id) {
		bool upedge = (id == d);
		bool downedge = (id == (n+d-1));
		int i = id%n;
		for(int j=0; j < m; ++j) {
			if(mp[i][j]) {
				al[i*m+j].push_back(n*m+(j+1)%m);
				al[n*m+(j+1)%m].push_back(i*m+j);
				al[i*m+j].push_back(n*m+(j)%m);
				al[n*m+(j)%m].push_back(i*m+j);

				if(!upedge && mp[(i-1+n)%n][j]) {
					al[i*m+j].push_back(((i-1+n)%n)*m+j);
					al[((i-1+n)%n)*m+j].push_back(i*m+j);
				}
				if(!downedge && mp[(i+1+n)%n][j]) {
					al[i*m+j].push_back(((i+1+n)%n)*m+j);
					al[((i+1+n)%n)*m+j].push_back(i*m+j);
				}
			}
		}
	}

	ap = vi(n*m+m, 0);
	visited = vi(n*m+m, 0);

	dfs(0, -1, 0);

	bool good = true;

	for(int i=0; i < n; ++i) {
		for(int j=0; j < m; ++j) {
			if(mp[i][j]) {
				good = good && visited[i*m+j];
			}
		}
	} 

	if(good) {
		for(int j=0; j < m; ++j) {
			if(!ap[n*m+j]) {
				ans.emplace_back(d, j);
			}
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n >> m;

	mp = vvi(n, vi(m, 0));

	for(int i=0; i < n; ++i) {
		string s;
		cin >> s;
		for(int j=0; j < m; ++j) {
			mp[i][j] = s[j] == '.';
		}
	}

	for(int i=0; i < n; ++i) {
		process_shift(i);
	}

	cout << ans.size() << "\n";
	for(int i=0; i < (int)ans.size(); ++i) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}


	
}