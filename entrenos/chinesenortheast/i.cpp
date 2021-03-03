#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<vi> vvi;

vvi al;
vi visited;

void dfs(int v) {
	if(visited[v]) return;
	visited[v] = 1;
	for(int i=0; i < (int)al[v].size(); ++i) {
		dfs(al[v][i]);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while(cin >> n) {
		al = vvi(n, vi());
		int ans = 0;
		for(int i=0; i < n; ++i) {
			for(int j=0; j < n; ++j) {
				int x;
				cin >> x;
				if(x == 1) {
					al[i].push_back(j);
					al[j].push_back(i);
					ans++;
				}
			}
		}
		ans /= 2;
		visited = vi(n);
		for(int i=0; i < n; ++i) {
			if(!visited[i]) {
				dfs(i);
				ans++;
			}
		}
		ans--;

		cout << ans << '\n';
	}
}