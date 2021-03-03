#include<bits/stdc++.h>


using namespace std;

typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;


vvi ansv;
vvii dp;
vi perm;
 int n, m, c;

void rec_ans(int d, int prev_k, int prev_c) {
    if(d == -1) return;
    int cur_c = prev_c;
    if(d == 0) {
        
    }
    else {
        rec_ans(d-1, dp[d][prev_c].first, dp[d][prev_c].second);
    }
    int nc = cur_c; 
    
  /*  cerr << "d = " << d << " prev_k = " << prev_k << " cur_c = " << cur_c <<  endl;
    
    cerr << "curr permutation" << endl;
    for(int i=0; i < n; ++i) {
        cerr << perm[i] << " ";
    }
    cerr << endl;*/
    
    for(int i=prev_k; i < prev_k+m; ++i) {
            ansv[d][perm[i]] = 1;
            if(i < cur_c) nc--;
            else nc++;
    }
    for(int i=0; i < min(n-prev_k, n-cur_c); ++i) {
        swap(perm[prev_k+i], perm[cur_c+i]);
    }
    
   /* cerr << "aft permutation" << endl;
    for(int i=0; i < n; ++i) {
        cerr << perm[i] << " ";
    }
    cerr << endl;*/
    
    return;
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
       
        cin >> n >> m;
        string s;
        cin >> s;
        c = 0;
        
        perm = vi(n,0);
        vi is_perm = vi(n, 0);
        for(int i=0; i < (int)s.length(); ++i) {
            if(s[i] == '0') {
                perm[c] = i;
                is_perm[i]=1;
                ++c;
            }
        }
        int nc = c;
        for(int i=0; i < n; ++i) {
            if(!is_perm[i]) {
                perm[nc] = i;
                ++nc;
            }
        }
        dp = vvii(n+1, vii(n+1, {-1, -1}));
        dp[0][c] = {0, 0};
        for(int i=0; i < n; ++i) {
            
            
            
            
            
            
            
            
            
           /* cerr << "Day " << i << ", possible: " << endl;
            for(int j=0; j <= n; ++j) {
                if(dp[i][j].first > -1) cerr << j << " ";
            }
            cerr << endl;*/
            
            
            
            
            
            for(int j=0; j <= n; ++j) {
                if(dp[i][j].first > -1) {
                    int cnt = 0;
                    if(j >= m) cnt = j-m;
                    else cnt = m-j;
                    dp[i+1][cnt] = {0, j};
                    
                //    cerr << "j = " << j << endl;
                    
                    for(int k=1; k < n-m+1; ++k) {
                        
               //         cerr << "k=" << k << ", b " << cnt << endl;
                        
                        if(k+m-1 > j-1) cnt++;
                        else cnt--;
                        if(k-1 > j-1) cnt--;
                        else cnt++;
                        dp[i+1][cnt] = {k, j};
                        
               //         cerr << "k=" << k << ", a " << cnt << endl;
                    }
                }
            }
        }
        int ansd = -1;
        for(int i=0; i <= n; ++i) {
            if(dp[i][0].first > -1) {
                ansd = i;
                break;
            }
        }
        if(ansd == -1) {
            cout << "CATACLYSM IMMINENT - TIME TO HOARD FACE MASKS" << endl;
        }
        else {
            cout << ansd << endl;
            ansv = vvi(ansd, vi(n, 0));
            rec_ans(ansd-1, dp[ansd][0].first, dp[ansd][0].second);
            for(int i=0; i < ansd; ++i) {
                for(int j=0; j < n; ++j) {
                    cout << ansv[i][j];
                }
                cout << endl;
            }
        }
    }
}
