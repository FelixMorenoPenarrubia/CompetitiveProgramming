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
   string a = "atcoder";
   while(T--) {
   	string s;
   	cin >> s;
   	bool good = false;
   	int ans = 0;
   	if(s > a) {
   		cout << 0 << endl;
   		continue;
   	}
   	for(int i=0; i < (int)s.length(); ++i) {
   		if(s[i] != 'a') {
   			if(s[i] > 't' && i > 0) ans = i-1;
   			else ans = i;
   			good = true;
   			break;
   		}
   	}
   	if(good) cout << ans << endl;
   	else cout << -1 << endl;
   }

}





