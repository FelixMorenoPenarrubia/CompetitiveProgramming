#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

void caso(int r, int c, ll h) {
    vvi grid = vvi(r, vi(c, 0));
    ii st;
    ii en;
    for(int i=0; i < r; ++i) {
        string s;
        cin >> s;
        for(int j=0; j < c; ++j) {
            if(s[j] == 'S') {
                st = ii(i, j);
            }
            if(s[j] == 'T') {
                en = ii(i, j);
            }
            if(s[j] == '#') {
                grid[i][j] = 1;
            }
        }
    }
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, st.first*c+st.second));
    vector<bool> visited (r*c);
    vector<ii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    ll sol = 0;
    while(!pq.empty()) {
        ii pos = pq.top();
        pq.pop();
        ll d = pos.first;
        int i = pos.second/c;
        int j = pos.second%c;
        if(visited[pos.second]) continue;
        visited[pos.second] = true;
        if(ii(i, j) == en) {
            sol = d;
            break;
        }
        for(int z=0; z < 4; ++z) {
            int di = dir[z].first;
            int dj = dir[z].second;
            if(i+di < r and i+di >= 0 and j+dj < c and j+dj >=0) {
              if(not visited[(i+di)*c+j+dj]) {
                    if(grid[i+di][j+dj] == 1) {
                            pq.push(ii(d+h+1, (i+di)*c+j+dj));
                    }
                    else {
                        pq.push(ii(d+1, (i+di)*c+j+dj));
                    }
              }
            }
        }
    }
    cout << sol << endl;
    
}

int main() {
    int r, c;
    ll h;
    while(cin >> r >> c >> h) caso(r, c, h);
}
