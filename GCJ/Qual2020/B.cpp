#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;


string solve(string s, int d) {
    if(d > 9) return s;
    int n = s.length();
    string ans = "";
    bool opened = false;
    int oi = 0;
    for(int i=0; i < n; ++i) {
        if(opened) {
            if(s[i] != char(d+'0')) {
               
            }
            else {
                opened = false;
                ans += solve(s.substr(oi, i-oi), d+1);
                ans += ')';
                ans += s[i];
            }
        }
        else {
            if(s[i] != char(d+'0')) {
                opened = true;
                ans += '(';
                oi = i;
            }
            else {
                ans += s[i];
            }
        }
    }
    if(opened) {
        ans += solve(s.substr(oi, n-oi), d+1);
                ans += ')';
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t=0; t < T; ++t) {
        string s;
        cin >> s;
        string ans = solve(s, 0);
        cout << "Case #" << t+1 << ": " << ans << "\n";
    }
}
