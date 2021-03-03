#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t=0; t < T; ++t) {
        ll l, r;
        cin >> l >> r;
        ll n = 1;
        while(max(l, r) >= n) {
            if(l >= r) {
                l -= n;
            }
            else {
                r -= n;
            }
            n++;
        }
        cout << "Case #" << t+1 << ": " << n-1 << " " << l << " " << r << endl;
        
        
    }
    
}
