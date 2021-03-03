#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


ii operator+( ii a, ii b) {
	return ii(a.first+b.first, a.second+b.second);
}

inline ll iabs(ll x) {
	return x > 0 ? x : -x;
}
inline ll xorpart(ii pos) {
	return ((iabs(pos.x)+1)^(iabs(pos.y)+1));
}
inline ll score(ii pos, ll i) {
	return i*xorpart(pos)+i;
}


int main() {


	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin >> n;
	string s;
	cin >> s;

	vii pos;
	ii cpos = ii(0, 0);
	pos.push_back(cpos);

	for(int i=0; i < n; ++i) {
		if(s[i] == 'L') {
			cpos.first--;
		}
		else if(s[i] == 'D') {
			cpos.second--;
		}
		else if(s[i] == 'R') {
			cpos.first++;
		}
		else if(s[i] == 'U') {
			cpos.second++;
		}
		pos.push_back(cpos);
	}

	vii dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	vi scores(5, 0);
	vector<map<ii, ll> > vis(5);

	for(int i=0; i <= n; ++i) {
		for(int z=0; z < 4; ++z) {
			ii rpos = pos[i]+dir[z];
			vis[z][rpos]++;
			scores[z] += score(rpos, vis[z][rpos]);
		}	
	}


	for(int i=0; i < n; ++i) {
		for(int z=0;  z < 4; ++z) {
			ii rpos = pos[i]+dir[z];
			scores[z] -= score(rpos, vis[z][rpos]+vis[4][rpos]);
			vis[z][rpos]--;
		}


		int zc;
		if(s[i] == 'L') zc = 2;
		else if(s[i] == 'D') zc = 3;
		else if(s[i] == 'R') zc = 0;
		else if(s[i] == 'U') zc = 1;

		cout << scores[4]+scores[zc] << "\n";

		vis[4][pos[i]]++;
		scores[4] += score(pos[i], vis[4][pos[i]]);

		for(int z=0;  z < 4; ++z) {
			scores[z] += (xorpart(pos[i])+1)*vis[z][pos[i]];
		}


	}
	

	


	
	

}