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
        int n;
        ll d;
        cin >> n >> d;
        vi a(n);
        map<ll, ll> cnt;
        for(auto &x : a) {
            cin >> x;
            cnt[x]++;
        }
        sort(a.begin(), a.end());
        vi b;
        for(auto it=cnt.begin(); it != cnt.end(); ++it) {
            b.push_back(it->first);
        }
        
        ll m = b.size();
        vvi mults = vvi(m, vi());
        
        for(int i=0; i < m; ++i) {
            for(int j=i+1; j < m; ++j) {
                if(b[j]%b[i] == 0) {
                    mults[i].push_back(j);
                    
                 //  cerr << "mult" << endl;
                }
            }
        }
        
        
        ll ans = d-1;
        for(ll i=0; i < m; ++i) {
            ll rem = d-cnt[b[i]];
            ll cc = 0;
            random_shuffle(mults[i].begin(), mults[i].end());
            for(ll j=0; j < (int)mults[i].size() and rem > 0; ++j) {
                ll jp = j;
                j = mults[i][j];
              //  cerr << "b[i] = " << b[i] << " b[j] = " << b[j] << endl;
                
               ll k = b[j]/b[i];
               
              // cerr << "i = " << i << " j = " << j << " b[i] = " << b[i] << " b[j] = " << b[j] << " k = " << k << endl;
               
                if(rem > cnt[b[j]]*k) {
                    rem -= cnt[b[j]]*k;
                    cc += cnt[b[j]]*(k-1);
                }
                else {
                    cc += (rem/k)*(k-1) + rem%k;
                    rem = 0;
                }
                    
                   j = jp; 
                
            }
        //    cerr << "i = " << i << endl;
          //   cerr << "cc aft " << cc << endl;
            // cerr << "rem aft " << rem << endl;
            for(ll j=m-1; j > i and rem > 0; --j) {
                if(b[j]%b[i]) {
                    if(rem > cnt[b[j]]*(b[j]/b[i])) {
                        rem -= cnt[b[j]]*(b[j]/b[i]);
                        cc += cnt[b[j]]*(b[j]/b[i]);
                    }
                    else {
                        cc += rem;
                        rem = 0;
                    }
                }
            }
            
            
            if(rem <= 0) ans = min(ans, cc);
        }
        
        cout << "Case #" << t+1 << ": " << ans << endl;
        
    }
}





