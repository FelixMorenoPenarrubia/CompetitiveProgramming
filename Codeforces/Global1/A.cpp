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
	int b, k;
	cin >> b >> k;
	int a;
	int p = 0;
	for(int i=0; i < k-1; i++) {
		cin >> a;
		p += (b%2)*(a%2);
	}
	cin >> a;
	p += a;
	cout << (p%2 ? "odd" : "even") << endl;
}
