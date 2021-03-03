#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

bool desc(ii a, ii b) {
	return a > b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	ll h;
	cin >> h;
	vi a(n);
	for(int i=0; i < n; i++) cin >> a[i];
	vii ap;
	for(int i=0; i < n; i++) ap.push_back(ii(a[i], i));
	sort(ap.begin(), ap.end(), desc);
	int l = 0;
	int r = n-1;
	while(r-l > 0) {
		int d = (r+l)/2;
		if(r-l == 1) d++;
		bool good = true;
		bool oc = false;
		ll ch = 0;
		for(int i=0; i < n; i++) {
			if(oc) {
				if(ap[i].second <= d) {
					oc = false;
				}
			}
			else {
				if(ap[i].second <= d) {
					if(ap[i].first + ch <= h) {
						ch += ap[i].first;
						oc = true;
					}
					else {
						good = false;
						break;
					}
				} 
			}
		}
		if(good) l = d;
		else r = d-1;
		
	}
	cout << l+1 << endl;
}
