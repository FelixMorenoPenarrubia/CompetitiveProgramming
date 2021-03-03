#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second

#define int ll

//typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

bool symmetrizer = false;

int n;

ii operator+(ii a, ii b) {
	return ii(a.x+b.x, a.y+b.y);
}

ii operator-(ii a, ii b) {
	return ii(a.x-b.x, a.y-b.y);
}

int operator^(ii a, ii b) {
	return a.x*b.y-a.y*b.x;
}

int operator*(ii a, ii b) {
	return a.x*b.x+a.y*b.y;
}


ii sym(ii a) {
	return ii(n+1-a.x, n+1-a.y);
}

bool ask(ii a, ii b, ii c) {
	if(symmetrizer) {
		a = sym(a);
		b = sym(b);
		c = sym(c);
	}
	ii v1 = b-a;
	ii v2 = c-a;
	if((v1^v2) == 0) {
		if((v1*v2) > 0) {
			if((v1*v1) > (v2*v2)) swap(a, c);
			else swap(a, b);
		}
		if(a == b && b == c) {
			cout << "? 1 " << a.x << " " << a.y << endl;
		}
		else {
			cout << "? 2 " << b.x << " " << b.y << " " << c.x << " " << c.y << endl;
		}
	}
	else {
		cout << "? 3 " << a.x << " " << a.y << " " << b.x << " " << b.y << " " << c.x << " " << c.y << endl;
	}
	string s;
	cin >> s;
	return (s == "Yes");
}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n;
	ii ans;

	if(not ask(ii(1, 1), ii(n, 1), ii(1, n))) {
		symmetrizer = true;
	}
	int l = 0;
	int r = n;
	while(r > l+1) {
		int mid = (l+r)/2;
		if(ask(ii(1, 1), ii(1, n), ii(mid, 1))) {
			r = mid;
		}
		else {
			l = mid;
		}
	}

	int xc = r;

	//cerr << "xc = " << xc << endl;

	l = -1;
	r = n-1;
	while(r > l+1) {
		int mid = (l+r)/2;
		if(ask(ii(1, n-mid), ii(1, n), ii(n, n-mid))) {
			r = mid;
		}
		else {
			l = mid;
		}
	}

	int yc = n-r;

	//cerr << "yc = " << yc << endl;

	
	if(xc == 1) {
		ans = ii(xc, yc);
	}
	else {

		ll u = ((xc-1)*(yc-1))/(n-1);
		if(((xc-1)*(yc-1))%(n-1)) u++;
		ans = ii(xc-u, yc);
	}
	
	if(symmetrizer) ans = sym(ans);
	
	cout << "! " << ans.x << " " << ans.y << endl;

	
}