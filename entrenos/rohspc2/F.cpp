#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    ll ans = n*((n-1)/2);
    if(n%3 ==0) {
        ans -= 2*(n/3);
    }
    cout << ans << endl;
}
