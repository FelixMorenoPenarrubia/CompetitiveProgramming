#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<bool> vb;
vi xr, yr;
vector<vb> isOccupied;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int xk, yk;
	cin >> xk >> yk;
	xr = vi(666);
	yr = vi(666);
	isOccupied = vector<vb>(1000, vb(1000, false));
	for(int i=0; i < 666; i++) {
		cin >> xr[i] >> yr[i];
		isOccupied[xr[i]][yr[i]] = true;
	}
	while(xk != 500 or yk != 500) {
		int dx, dy;
		if(xk > 500) dx = -1;
		else if(xk < 500) dx = 1;
		else dx = 0;
		if(yk > 500) dy = -1;
		else if(yk < 500) dy = 1;
		else dy = 0;
		
		if(isOccupied[xk+dx][yk+dy]) {
			cout << xk+dx << " " << yk << endl;
			return 0;
		}
		else {
			cout << xk+dx << " " << yk+dy << endl << endl;
			xk += dx;
			yk += dy;
			int k, mx, my;
			cin >> k >> mx >> my;
			if(k == -1 or k == 0) return 0;
			k--;
			isOccupied[xr[k]][yr[k]] = false;
			isOccupied[mx][my] = true;
			xr[k] = mx;
			yr[k] = my;
		}
	}
	int d1 = 0;
	int d2 = 0;
	int d3 = 0;
	int d4 = 0;
	for(int i=0; i < 666; ++i) {
		if(xr[i] < 500) {
			d1++, d4++;
			if(yr[i] < 500) {
				d2++;
			}
			else {
				d3++;
			}
			
		}
		else if(xr[i] > 500){ 
			d2++, d3++; 
			if(yr[i] < 500) {
				d1++;
			}
			else {
				d4++;
			}
		}
		
	}
	int dx, dy;
	int md = max(d1, max(d2, max(d3, d4)));
	if(md == d1) dx = -1, dy = -1;
	else if(md == d2) dx = 1, dy = -1;
	else if(md == d3) dx = 1, dy = 1;
	else dx = -1, dy = 1;
	while(true) {
		if(isOccupied[xk+dx][yk+dy]) {
			cout << xk+dx << " " << yk << endl;
			return 0;
		}
		else {
			cout << xk+dx << " " << yk+dy << endl << endl;
			xk += dx;
			yk += dy;
			int k, mx, my;
			cin >> k >> mx >> my;
			if(k == -1 or k == 0) return 0;
			k--;
			isOccupied[xr[k]][yr[k]] = false;
			isOccupied[mx][my] = true;
			xr[k] = mx;
			yr[k] = my;
		}
	}
}
