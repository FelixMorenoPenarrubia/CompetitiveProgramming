#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
    	int n;
    	cin >> n;
    	vi a(n);
    	int x = 0;
    	for(int i=0; i < n; ++i) {
    		cin >> a[i];
    		x ^= a[i];
    	}
    	int win = n%2;
    	if(!win && x ==0) win = !win;
    	cout << (win ? "Second" : "First") << endl;
    }
    

}





