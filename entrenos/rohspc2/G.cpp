#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;


vvi dp;

const ll MAX_VAL = 1e18;

ll f(int n, int k) {
    ll& r = dp[n][k];
    if(r == -1) {
        if(n == 0) {
            r = (k == 0) ? 1 : 0;
        }
        else {
            if(k == 0) {
                r = f(n-1, 1);
            }
            else {
                r = f(n-1, k-1)+f(n-1, k+1);
                if(r > MAX_VAL or f(n-1, k-1) == -2 or f(n-1, k+1) == -2) {
                    r = -2;
                }
            }
        }
    }
    return r;
}

string get_k_seq(int n, int b, ll k) {
    if(n == 0) return "";
    if(b == 0) return "{"+get_k_seq(n-1, b+1, k);
    if(f(n-1, b+1) >= 0 and f(n-1, b+1) < k) return "}"+get_k_seq(n-1, b-1, k-f(n-1, b+1));
    else return "{"+get_k_seq(n-1, b+1, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    ll k;
    cin >> s >> k;
    int n = s.length();
    dp = vvi(65, vi(67, -1));
   /* for(int i=0; i < 10; ++i) {
        cerr << f(2*i, 0) << endl;
    }*/
    int pl = 0;
    for(int i=1; i < n; ++i) {
        if(s[i] == '-' and s[i-1] == '-') pl++;
    }
    if(pl%2) {
        int idx;
       // cerr << "Hi" << endl;
       // cerr << pl << endl;
        //cerr << f(pl+1, 0) << endl;
        if(f(pl+1, 0) == -2) {
            idx = n;
        }
        else {
            idx = n;
            while(k > f(pl+1, 0) and idx >= 0) {
                k -= f(pl+1, 0);
                idx--;
            }
            if(idx < 0) {
                cout << "Overflow" << endl;
                return 0;
            }
        }
        string br = get_k_seq(pl+1, 0, k);
        int j = 0;
        string ans = "";
        for(int i=0; i <= n; ++i) {
            if(i > 0 and i < n and s[i] == '-' and s[i-1] == '-') {
                ans += br[j];
                ++j;
            }
            if(i == idx) {
                ans += br[j];
                ++j;
            }
            if(i < n) ans += s[i];
        }
        cout << ans << endl;
    }
    else {
        if(f(pl, 0) < k and f(pl, 0) >= 0) {
            cout << "Overflow" << endl;
            return 0;
        }
        string br = get_k_seq(pl, 0, k);
        int j = 0;
        string ans = "";
        for(int i=0; i < n; ++i) {
            if(i > 0 and s[i] == '-' and s[i-1] == '-') {
                ans += br[j];
                ++j;
            }
            ans += s[i];
        }
        cout << ans << endl;
    }
    
}
