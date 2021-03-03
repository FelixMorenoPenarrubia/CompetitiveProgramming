#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

void game() {
	//First phase;
	ll x = 2;
	ll y = 1;
	while(x < 2e9) {
		cout << "? " << x << " " << y << endl << endl;
		char ans;
		cin >> ans;
		if(ans == 'x') {
			x *= 2;
			y *= 2;
		}
		else if(ans == 'y') {
			break;
		}
		else return;
	}
	if(x >= 2e9) {
		cout << "! 1" << endl << endl;
		return;
	}
	ll l = y;
	ll r = x;
	while(r-l > 0) {
		ll d = (r+l)/2;
		cout << "? " << r << " " << d << endl << endl;
		char ans;
		cin >> ans;
		if(ans == 'x') {
			r = d;
		}
		else if(ans == 'y') {
			l = d+1;
		}
		else return;
	}
	cout << "! " << l << endl << endl;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	string g;
	while(cin >> g and g == "start") {
		game();
	}
}
