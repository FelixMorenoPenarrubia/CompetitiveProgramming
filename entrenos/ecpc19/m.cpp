#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll INF = 1e18;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("plants.in", "r", stdin);

	string n;
	cin >> n;

	bool ani = true;
	bool ni = true;
	for(int i=0; i < (int)n.length(); ++i) {
		if(n[i] != '9') {
			ani = false;
			if(i > 0) ni = false;
		}
	}
	if(ani) cout << 9*n.length() << endl;
	else if(ni) cout << 9*(n.length()-1) + (n[0]-'0') << endl;
	else cout << 9*(n.length()-1) + (n[0]-'1') << endl;

}