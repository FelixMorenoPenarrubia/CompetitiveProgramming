#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vi d;
vvi st;

int rmq(int l, int r) {
	int i = 0;
	while((1<<i) <= (r-l+1)) i++;
	i--;
	return min(st[l][i], st[r-(1<<i)+1][i]);
}

int main() {
	int n;
	cin >> n;

	vi a(n);
	for(int i=0; i < n; ++i) cin >> a[i];


	sort(a.begin(), a.end());

	d = vi(n-1);
	for(int i=0; i < n-1; ++i) d[i] = a[i+1]-a[i];

	st = vvi(n-1, vi(22, 0));

	for(int i=0; i < n-1; ++i) {
		st[i][0] = d[i];
	}
	for(int i=1; (1<<i) <= n-1; ++i) {
		for(int j=0; j < n-1; ++j) {
			if(j+(1<<(i-1)) < n-1)st[j][i] = min(st[j][i-1], st[j+(1<<(i-1))][i-1]);
			else st[j][i] = st[j][i-1];
		}
	}

	
	int ans = -1;

	for(int i=0; i+6 < n; ++i) {
		int fsum = a[i]+a[i+1]+a[i+2]+a[i+3];
		int maxp2 = fsum-a[i+4];

		int l = i+5;
		int r = n-1;
		while(r-l > 1) {
			int mid = (l+r)/2;
			if(a[mid] < maxp2) {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		int ip2 = l;

		if(a[ip2] >= maxp2) continue;

		int maxp1 = a[i+4]+a[ip2];
		l = ip2+1;
		r = n;
		while(r-l > 1) {
			int mid = (l+r)/2;
			if(a[mid] < maxp1) {
				l = mid;
			}
			else {
				r = mid;
			}
		}

		int ip1 = l;

		if(a[ip1] < a[i+4]+a[ip2]) {
			ans = max(ans, a[ip1]+a[i+4]+a[ip2]+fsum);
		} 
		else {
			int maxdiff = a[i+4];

			l = i+5;
			r = ip2+1;
			while(r-l > 1) {
				int mid = (l+r)/2;
				if(rmq(mid, ip2) <  maxdiff) {
					l = mid;
				}
				else {
					r = mid;
				}
			}

			ip2 = l;
			ip1 = l+1;
			if(a[ip1] < a[i+4]+a[ip2]) {
				ans = max(ans, a[ip1]+a[i+4]+a[ip2]+fsum);
			} 
		}
	}

	cout << ans << endl;

}