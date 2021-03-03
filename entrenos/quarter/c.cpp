#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pi;

int nn;
bool pos;
vector <vector <int> >ans;

void apply_perm(vector <int>& v, vector <int>& p) {
	vector <int>a(v.size());
	for (int i = 0; i < p.size(); ++i) {
		a[p[i]] = v[i];
	}
	for (int i = 0; i < p.size(); ++i) v[i] = a[i];
}

void gen(int n, int k, int t) {
	if (n == k) {
		vector <int>id(nn, 0);
		for (int i = 0; i < n; ++i) id[i] = 1;
		ans.push_back(id);		
		return;
	}
	if (k == 0) {
		vector <int>zer(nn, 0);
		ans.push_back(zer);		
		return;
	}
	gen(n-1, k, t);
	if (ans.size() < t) {
		int x = ans.size();
		gen(n-1, k-1, t);
		vector <int>v1;
		for (int i = 0; i < n; ++i) {
			if (ans[x-1][i]) {
				v1.push_back(i);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (!ans[x-1][i]) {
				v1.push_back(i);
			}
		}
		vector <int>v2;
		for (int i = 0; i < n; ++i) {
			if (ans[x][i]) {
				v2.push_back(i);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (!ans[x][i]) {
				v2.push_back(i);
			}
		}
		vector <int>p(n);
		for (int i = 0; i < n; ++i) p[v2[i]] = v1[i]; 
		for (int i = x; i < ans.size(); ++i) {
			ans[i][n-1] = 1;
			apply_perm(ans[i], p);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, t;
    cin >> nn >> k >> t;
    gen(nn, k, t);
    if (ans.size() < t) cout << 0 << '\n';
    else{
		cout << t << '\n';
		for (int i = 0; i < ans.size(); ++i) {
			int cur = 0;
			for (int j = 0; j < nn; ++j) {
				if (ans[i][j]) {
					if (cur != 0) cout << " ";
					cur++;
					cout << j+1;
				}
			}
			cout << '\n';
		}
	}
}
