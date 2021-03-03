#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, vi> groups;
    for(int i=0; i < n; ++i) {
        string s, t;
        cin >> s >> t;
        int l = t.length();
        vi charset = vi(26, 0);
        for(int j=0; j < l; ++j) {
            charset[t[j]-'a'] = 1;
        }
        t = "";
        for(char c='a'; c <= 'z'; ++c) {
            if(charset[c-'a']) t += c;
        }
        
        l = s.length();
        for(int j=l-1; j >= -1; --j) {
            if( j > -1 and charset[s[j]-'a']) {
                    
            }
            else {
                s = s.substr(0, j+1);
                break;
            }
        }
        cerr << s << " " << t << endl;
        groups[s+"."+t].push_back(i);
    }
    cout << groups.size() << endl;
    for(auto it=groups.begin(); it != groups.end(); ++it) {
        vi v = it->second;
        int m = v.size();
        cout << m << " ";
        for(int i=0; i < m; ++i) cout << v[i]+1 << " ";
        cout << "\n";
    }
}
