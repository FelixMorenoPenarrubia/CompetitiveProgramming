#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

vvb grid;
vii ini;
vii fin;
bool same;
vvb visited;
ii fil;
int n;
void dfsin(ii p) {
	int x = p.first;
	int y = p.second;
	if(p.first < 0 or p.first >= n or p.second < 0 or p.second >= n or visited[p.first][p.second] or !grid[x][y]) return;
	ini.push_back(p);
	if(p == fil) same = true;
	visited[x][y] = true;
	dfsin(ii(x-1, y));
	dfsin(ii(x, y-1));
	dfsin(ii(x+1, y));
	dfsin(ii(x, y+1));
	
}
void dfsfin(ii p) {
	int x = p.first;
	int y = p.second;
	if(p.first < 0 or p.first >= n or p.second < 0 or p.second >= n or visited[p.first][p.second] or !grid[x][y]) return;
	fin.push_back(p);
	//if(p == fil) same = true;
	visited[x][y] = true;
	dfsfin(ii(x-1, y));
	dfsfin(ii(x, y-1));
	dfsfin(ii(x+1, y));
	dfsfin(ii(x, y+1));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n;
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	r1--;
	r2--;
	c1--;
	c2--;
	fil = ii(r2, c2);
	grid = vvb(n, vb(n));
	for(int i=0; i < n; i++) {
		string s;
		cin >> s;
		for(int j=0; j < n; j++) {
			grid[i][j] = (s[j] == '0');
		}
	}
	visited = vvb(n, vb(n, false));
	same = false;
	dfsin(ii(r1, c1));
	dfsfin(ii(r2, c2));
	if(same) {
		cout << 0 << endl;
		return 0;
	}
	ll mincost = 999999999;
	for(int i=0; i < ini.size(); i++) {
		for(int j=0; j < fin.size(); j++) {
			ll x1 = ini[i].first;
			ll y1 = ini[i].second;
			ll x2 = fin[j].first;
			ll y2 = fin[j].second;
			mincost = min(mincost, (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); 
		}
	}
	cout << mincost << endl;
	
}
