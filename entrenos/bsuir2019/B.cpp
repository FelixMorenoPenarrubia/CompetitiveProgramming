#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int zc = 0;
vvi al;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
   
    int n, m;
    cin >> n >> m;
    vvi mat(n, vi(m));
    int k;
    cin >> k;
    int a, b;
    cin >> a >> b;
    vii zeroes;
    for(int i=0; i < n; ++i) {
        for(int j=0; j < m; ++j) {
            cin >> mat[i][j];
            if(mat[i][j] == 0) {
                zc++;
                zeroes.emplace_back(i, j);
            }
        }
    }
    
    al = vvi(2*zc, vi());
    for(int i=0; i < zc; ++i) {
        for(int j=i+1; j < zc; ++j) {
            int x0 = zeroes[i].first;
            int y0 = zeroes[i].second;
            int x1 = zeroes[j].first;
            int y1 = zeroes[j].second;
            
            if(mat[x0][y1] == a and mat[x1][y0] == a) {
                al[2*i].push_back(2*j+1);
            }
            else if(mat[x0][y1] == b and mat[x1][y0] == b) {
                al[2*i+1].push_back(2*j);
            }
        }
    }
    
    vvi acol(n, vi(m));
    vvi bcol(n, vi(m));
    vvi arow(n, vi(m));
    vvi brow(n, vi(m));
    
    for(int i=0; i < n; ++i) {
        
    }
    
    for(int i=0; i < zc; ++i) {
        int x0 = zeroes[i].first;
        int y0 = zeroes[i].second;
        for(int y=0; y < m; ++y) {
            if(mat[x0][y] == a) {
                
            }
            
        }
    }
    
}
