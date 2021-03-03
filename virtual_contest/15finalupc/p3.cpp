#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll x;
    while(cin >> x) {
        ll i = 0;
        while((1LL<<i)-1LL < x) ++i;
        cout << (1LL<<i)-1LL << endl;
    }
}
