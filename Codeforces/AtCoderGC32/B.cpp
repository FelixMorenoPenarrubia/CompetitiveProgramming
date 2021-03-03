#include<bits/stdc++.h>

using namespace std;

typedef long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int n;
vi c;
vi dp;
vvi fa;
vvi coldp;
vi cpos;
vi colorlist;
ll mod = 1e9+7;

ll f(int i);
ll colf(int col, int l) {
	
	int m = fa[col].size();
	if(l >= m) return 0;
	 if(coldp[col][l] == -1) {
		coldp[col][l] = (f(fa[col][l]+1)+colf(col, l+1))%mod;
		
	}
	return coldp[col][l];
}
ll f(int i) {
	if(i == n) return 1;
	else if(i > n) return 0;
	if(dp[i] == -1) {
		//cerr << "COMPUTING f(" << i << ")" << endl;
		dp[i] = 0;
		
		//int m = fac.size();
		int l = 0;
		//int r = fa[c[i]].size()-1;
		/*while(r-l > 0) {
			int d = (l+r)/2;
			if(fa[c[i]][d] < i) {
				l = d+1;
			}
			else if(fa[c[i]][d] == i) {
				l = d;
				r = d;
			}
			else {
				r = d-1;
			}
		}*/
		l = cpos[i];
		/*
		for(int j = l+1; j < m; j++) {
			dp[i] += f(fac[j]+1);
			dp[i] %= mod;
		}*/
		dp[i] += colf(c[i], l+1);
		dp[i] += f(i+1);
		dp[i] %= mod;
		//cerr << "f(" << i <<") = " << dp[i] << endl;
	}
	return dp[i]%mod;
	
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n;
	
	
	int prevcolor = -1;
	int in_n = n;
	fa = vvi(2e5, vi());
	for(int i=0; i < in_n; i++) {
		int color;
		cin >> color;
		color--;
		if(color != prevcolor) {
			fa[color].push_back(i-(in_n-n));
			if(fa[color].size() == 1) colorlist.push_back(color);
			c.push_back(color);
			cpos.push_back(fa[color].size()-1);
		}
		else n--;
		prevcolor = color;
		
	}
	dp = vi(n, -1);
	coldp = vvi(2e5, vi());
	for(int i=0; i < colorlist.size(); i++) {
		int col =colorlist[i];
		coldp[col] = vi(fa[col].size(), -1);
	}
	for(int i=n-1; i > 0; i--) f(i);
	cout << f(0) << endl;
}
