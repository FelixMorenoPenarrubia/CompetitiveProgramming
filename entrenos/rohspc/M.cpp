#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int mxans = 0;
    int prev = -1;
    for(int i=0; i < n; ++i) {
        int c;
        cin >> c;
        if(c == prev) {
            ans = 1;
        }
        else {
            prev = c;
            ans++;
        }
        mxans = max(ans, mxans);
    }
    cout << mxans << endl;
}
