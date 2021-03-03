#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

vvi am;
vvi al
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	am = vvi(n, vi(m));
	for(int i=0; i < n; i++) {
		string s;
		cin >> s;
		for(int j=0; j < m; j++) {
			if(s[j] == '>') am[i][j] = 1;
			else if(s[j] == '=') am[i][j] = 0;
			else am[i][j] = -1;
		} 
	}
	for(int i=0; i < n; i++) {
		for(int 
	}
}
