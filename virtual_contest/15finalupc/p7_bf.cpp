#include<bits/stdc++.h>


using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef double ld;
typedef vector<ld> vld;

vld dp;

ld f(int n) {
    if(n < 0 or n > 1e7) return 0;
    if(dp[n] == -1.0) {
        dp[n] = ld(n);
        for(ld i=max(ld(1), floor(sqrt(ld(n))-100)); i <= min(ld(n), ceil(sqrt(ld(n))+100)); i += 1) {
            dp[n] = min(dp[n], (i*(i+1-2/i))/(2*n) + ((n-i)/n)*(f(int(n-i)))+1);
        }
    }
    return dp[n];
}

int main() {
    int n;
    cout.setf(ios::fixed);
    cout.precision(4);
    dp = vld(1e7+1, -1.0);
    dp[0] = dp[1] = 0.0;
    while(cin >> n) {
        
        cout << f(n) << endl;
        
    }
   
}
