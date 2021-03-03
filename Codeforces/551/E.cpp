#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	int h = 0;
	int headx = -1;
	int heady = -1;
	int tailx = -1;
	int taily = -1;
	while(h < n and tailx == -1) {
		cout << "? 1 " << h+1 << " "  << n << " " << h+1 << endl << endl;
		int res;
		cin >> res;
		if(res % 2 == 1) {
			int l = 0;
			int r = n-1;
			while(r-l > 0) {
				int d = (r+l)/2;
				cout << "? " << l+1 << " " << h+1 << " " << d+1 << " " << h+1 << endl << endl;
				cin >> res;
				if(res % 2 == 1) {
					r = d;
				}
				else {
					l = d+1;
				}
			}
			if(headx == -1) {
				headx = l;
				heady = h;
			}
			else {
				tailx = l;
				taily = h;
			}
		}
		++h;
	}
	h = 0;
	while(h < n and tailx == -1) {
		int res;
		if(h < n-1) {
		cout << "? " << h+1 << " 1 " << h+1 << " " << n << endl << endl;
		
		cin >> res;
		}
		else res = 1;
		if(res % 2 == 1) {
			int l = 0;
			int r = n-1;
			while(r-l > 0) {
				int d = (r+l)/2;
				cout << "? " << h+1 << " " << l+1 << " " << h+1 << " " << d+1 << endl << endl;
				cin >> res;
				if(res % 2 == 1) {
					r = d;
				}
				else {
					l = d+1;
				}
			}
			if(headx == -1) {
				headx = h;
				heady = l;
			}
			else {
				tailx = h;
				taily = l;
			}
		}
		++h;
	}
	cout << "! " << headx+1 << " " << heady+1 << " " << tailx+1 << " " << taily+1 << endl;
}

