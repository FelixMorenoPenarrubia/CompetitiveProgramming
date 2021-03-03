#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> v = vector<int>(k, 0);
    int ts = 0;
    for(int i=0; i < n; ++i) {
		int a;
		cin >> a;
		v[i%k] += a;
		ts += a;
	}
	int sol = 0;
	for(int i=0; i < k; i++) {
		sol = max(sol, abs(ts-v[i]));
	}
	cout << sol << endl;
    

}
