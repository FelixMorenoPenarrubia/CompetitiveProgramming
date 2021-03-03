#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int sn;
vector<vector<int>> g, gt;
vector<bool> visited;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    visited.assign(sn, false);
    for (int i = 0; i < sn; ++i) {
        if (!visited[i])
            dfs1(i);
    }

    comp.assign(sn, -1);
    for (int i = 0, j = 0; i < sn; ++i) {
        int v = order[sn - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(sn / 2, false);
    for (int i = 0; i < sn; i += 2) {
        if (comp[i] == comp[i + 1]) {
            return false;
        }
        assignment[i / 2] = comp[i] > comp[i + 1];

    }
    return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	sn = 2*n;
	g = vvi(2*n);
	gt = vvi(2*n);
	for(int i=0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[2*x].push_back(2*y+1);
		gt[2*y+1].push_back(2*x);
		g[2*y].push_back(2*x+1);
		gt[2*x+1].push_back(2*y);

		gt[2*x].push_back(2*y+1);
		g[2*y+1].push_back(2*x);
		gt[2*y].push_back(2*x+1);
		g[2*x+1].push_back(2*y);
	}
	for(int i=0; i < n; ++i) {
		if(g[2*i].empty()) {
			g[2*i].push_back(2*i+1);
			gt[2*i+1].push_back(2*i);
		}
	}

	if(solve_2SAT()) {
		int ans = 0;
		for(int i=0; i < n; ++i) {
			if(assignment[i]) ans++;
		}
		cout << min(ans, n-ans) << endl;
	}
	else {
		cout << -1 << endl;
	}
}