#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int n;
ll mod = 1e9+7;
vvi dp;
vi a;

ll rec(int i, int s) {
    if(i >= n) return 0;
    if(dp[i][s] == -1) {
        dp[i][s] = rec(i+1, s);
        if(a[i] == s) {
            dp[i][s] += n-i;
        }
        else if(a[i] < s) {
            dp[i][s] += rec(i+1, s-a[i]);
        }
        dp[i][s] %= mod;
    }
    return dp[i][s];
}

int main() {
    
    while(cin >> n) {
        a = vi(n);
        dp = vvi(n, vi(2049, -1));
        for(int i=0; i < n; ++i) {
            cin >> a[i];
        }
        cout << rec(0, 2048) << '\n';
    }
}
