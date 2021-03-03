#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    while(cin >> n) {
        ll evens = 0;
        ll odds = 0;
        for(int i=0; i < n; ++i) {
            ll x;
            cin >> x;
            if(x%2) {
                evens = max(evens, odds+x);
            }
            else {
                odds = max(odds, evens+x);
            }
        }
        cout << max(evens, odds) << endl;
    }
}
