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
	vi c = vi (n);
	int blah;
	for(int i=0; i < n; i++) { cin >> c[i]; cin >> blah; }
	int k;
	cin >> k;
	for(int i=0; i < n; i++) {
		if(k >= c[n-i-1]) { cout << i+1 << endl; break; }
	}
}
