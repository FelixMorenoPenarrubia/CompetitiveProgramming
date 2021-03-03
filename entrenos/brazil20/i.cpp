#include<bits/stdc++.h>

using namespace std;

#define int ll

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


const ll MOD = 1e9+7;

vi p;
vvi ch;
vi leaf;
vi ans;
vi ans2;


ll pot(ll x, ll e) {
	if(e == 0) return 1;
	ll sq =pot(x, e/2);
	if(e&1)	return (((sq*sq)%MOD)*x)%MOD;
	return (sq*sq)%MOD;
}

ll inv(ll x) {
	return pot(x, MOD-2);
}

void dfs(int v) {
	ll cans1 = 1;
	ll cans2 = 0;
	for(int i=0; i < (int)ch[v].size(); ++i) {
		dfs(ch[v][i]);
		cans1 *= ans[ch[v][i]];
		cans1 %= MOD;
		cans2 %= MOD;
		leaf[v] += leaf[ch[v][i]];
		
	}
	if(ch[v].size() == 0) { 
		leaf[v] = 1;
		ans[v] = 1;
		ans2[v] = 1;
	}
	/*else if(ch[v].size() == 1) {
		ans[v] = (cans1)%MOD;
		ans2[v] = (cans2+leaf[v])%MOD;
	}*/
	else {
		ll aans = 0;
		for(int i=0; i < (int)ch[v].size(); ++i) {
			aans += inv(ans[ch[v][i]])*cans1*ans2[ch[v][i]];
			aans %= MOD;
		}
		ans[v] =(cans1+aans)%MOD;
		ans2[v] = (cans2+leaf[v])%MOD;
	}
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	p = vi(n);
	leaf = vi(n);
	ch = vvi(n);
	ans = vi(n);
	ans2 = vi(n);
	for(int i=1; i < n; ++i) {
		cin >> p[i];
		p[i]--;
		ch[p[i]].push_back(i);
	}

	dfs(0);
	cout << ans[0] << endl;

}