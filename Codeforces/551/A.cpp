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
	int n, t;
	cin >> n >> t;
	int mwait = -1;
	int cm = -1;
	for(int i=0; i < n; ++i) {
		int s, d;
		cin >> s >> d;
		int wait;
		if(s >= t) wait = s-t;
		else if((t-s) % d == 0) wait = 0;
		else wait = d-(t-s)%d;
		if(cm == -1 or wait < mwait) {
			cm = i;
			mwait = wait;
		}
	}
	cout << cm+1 << endl;
}
