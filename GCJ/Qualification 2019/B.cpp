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
    int t;
    cin >> t;
    for(int k=0; k < t; ++k) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		
		cout << "Case #" << k+1 << ": ";
		for(int i=0; i <2*n-2; ++i) {
			if(s[i] == 'E') cout << 'S';
			else cout << 'E';
		}
		cout << endl;
	}
}
