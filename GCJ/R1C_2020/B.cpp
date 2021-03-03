#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t=0; t < T; ++t) {
        ll U;
        cin >> U;
        int N = 1e4;
        map<char, ll> freq;
        
        for(int i=0; i < N; ++i) {
            int q;
            cin >> q;
            string s;
            cin >> s;
            for(int j=0; j < (int)s.length(); ++j) {
                if(freq[s[j]] == 0) {
                    freq[s[j]] = 1;
                }
            }
            freq[s[0]]++;
            
        }
        string ans = string(10, '-');
        vector<pair<ll, char> > vf;
        for(auto it=freq.begin(); it != freq.end(); ++it) {
            vf.push_back(make_pair(-it->second, it->first));
        }
        sort(vf.begin(), vf.end());
        while(vf.size() < 10) {
            ans[0] = '0';
        }
        for(int i=1; i <= 9; ++i) {
            
           // cerr << "char " << it->first << " has freq " << -it->second << endl;
            
            ans[i] = vf[i-1].second;
            
        }
        ans[0] = vf[9].second;
        cout << "Case #" << t+1 << ": " << ans << endl;
        
    }
}
