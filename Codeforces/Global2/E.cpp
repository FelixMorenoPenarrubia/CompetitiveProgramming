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
	ll sol = 0;
	int o1 = 0;
	int o2 = 0;
	//int p1 = 0;
	//vi destroyers = vi();
	for(int i=0; i < n; i++) {
		ll a;
		cin >> a;
		sol += a/3;
		if(a % 3 == 1) {
			if(o2 > 0 and a > 1) {
				o2--;
				sol++;
			}
			else if(o1 > 1 and a > 1) {
				o1 -= 2;
				sol++;
			}
			else {
				if(a > 1) {
					//destroyers.push_back(
				}
				o1++;
			}
		}
		else if(a % 3 == 2) {
			if(o1 > 0) {
				o1--;
				sol++;
			}
			else if(o2 > 0) {
				o1++;
				o2--;
				sol++;
			}
			else {
				o2++;
			}
		}
		else if(a % 3 == 0) {
			if(o1 >= 3 and a >= 6) {
				sol+= 1;
				oi -= 3;
			}
			else if(o2 > 0) {
				 o2--;
				 o1+=2;
			 }
		}
	}
	cout << sol << endl;
}
