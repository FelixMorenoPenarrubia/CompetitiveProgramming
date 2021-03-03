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

    vi a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    ll sum = a[0]+a[1]+a[2]+a[3];
    bool ans = false;
    for(int i=0; i < 4; ++i) {
    	if(2*a[i] == sum) ans = true;
    	for(int j=i+1; j < 4; ++j) {
    		if(2*(a[i]+a[j]) == sum) ans = true;
    		for(int k=j+1; k < 4; ++k) {
    			if(2*(a[i]+a[j]+a[k]) == sum) ans = true;
    		}
    	}
    }
    cout << (ans ? "Yes" : "No") << endl;

    

}





