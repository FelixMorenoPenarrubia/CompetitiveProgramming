#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	ll n;
	cin >> n;
	ll val = (n*(n-1))/4;
	if(n%4 == 2 || n%4 == 3) val++;
	ll low = 1;
	ll upp = n;
	while(upp > low) {
		ll x = (upp+low)/2;
		if((n*(n-1))/2-((n-x)*(n-x-1))/2 >= val) {
			upp = x;
		}
		else {
			low = x+1;
		}
	}
	cout << low << endl;
	
}