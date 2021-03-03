#include<iostream>
#include<vector>

using namespace std;

typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;


ll mod = 1e9+7;




int main() {
    int n;
    while(cin >> n) {
        vi dp;
      //  a = vi(n);
        dp = vi(2049, 0);
       /* for(int i=0; i < n; ++i) {
            cin >> a[i];
        }*/
        for(int i=0; i < n; ++i) {
            int a;
            cin >> a;
            
            for(int s=2048-a; s > 0; --s) {
                dp[s+a] += dp[s];
          //      dp[s+a[i]] %= mod;
            }
            dp[a] += i+1;
           // dp[a[i]] %= mod;
            
        }
        

        
        cout << dp[2048] << '\n';
    }
}
