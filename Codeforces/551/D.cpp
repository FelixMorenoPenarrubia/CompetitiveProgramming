#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

vi mx;
vvi children;
vi dp;
int penalty(int v) {
	if(children[v].size() == 0) return 0;
	if(dp[v] != -1) return dp[v];
	if(mx[v] == 0) {
		/*vi pens;
		for(int i=0; i < children[v].size(); i++) {
			pens.push_back(penalty(children[v][i]));
			
		}
		sort(pens.begin(), pens.end());
		int cpen = -1;
		for(int i=0; i < children[v].size(); i++) {
			if(pens[i] > cpen) cpen = pens[i];
			else cpen++;
		}
		dp[v] = cpen;*/
		dp[v] = -1;
		for(int i=0; i < children[v].size(); i++) {
			dp[v] += penalty(children[v][i])+1;
			
		}
		
	}
	else {
		dp[v] = 1e7;
		for(int i=0; i < children[v].size(); i++) {
			dp[v] = min(dp[v], penalty(children[v][i]));
		}
		
	}
	return dp[v];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    mx = vi(n);
    dp = vi(n, -1);
    children = vvi(n, vi());
    for(int i=0; i < n; i++) cin >> mx[i];
    for(int i=1; i < n; i++) {
		int f;
		cin >> f;
		f--;
		children[f].push_back(i);
	}
	int k = 0;
	for(int i=0; i < n; i++) {
		if(children[i].size() == 0) k++;
	}
	cout << k - penalty(0) << endl;

}

