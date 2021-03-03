#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll n;
vi ufds;
vvi ufds_v;
void ufds_init() {
	ufds = vi(n);
	ufds_v = vvi(n);
	for(int i=0; i < n; i++) {
		ufds[i]=i;
		ufds_v[i].push_back(i);
	}
}
ll findSet(ll x) {
	if(ufds[x] == x) return x;
	return ufds[x] = findSet(ufds[x]);
}
void unionSet(ll x0, ll y0) {
	ll x = findSet(x0);
	ll y = findSet(y0);
	ufds[x] = y;
	ufds_v[y].push_back(x);
	/*ufds_v[x].clear();
	ufds_v[x].shrink_to_fit();*/
}
void recursive_print(ll st) {
	for(int i=0; i < ufds_v[st].size(); i++) {
		if(ufds_v[st][i] == st) {
			cout << st+1 << " ";
		}
		else recursive_print(ufds_v[st][i]);
	}
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n;
	ufds_init();
	for(int i=0; i < n-1; i++) {
		ll x, y;
		cin >> x >> y;
		x--;
		y--;
		unionSet(x, y);
	}
	ll st = findSet(0);
	recursive_print(st);
	
}
