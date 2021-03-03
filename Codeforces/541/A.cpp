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
	ll w1, h1, w2, h2;
	cin >> w1 >> h1 >>w2 >> h2;
	if(w2 > w1) swap(w1, w2), swap(h1, h2);
	cout << 2*(w1+h1)+4+2*h2 << endl;
	
}
