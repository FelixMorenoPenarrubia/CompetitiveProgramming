#include<bits/stdc++.h>


using namespace std;

typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;


ll INF = 1e9;

struct cell_st {
    int i, j, p, s;
    cell_st() {
        
    }
    cell_st(int _i, int _j, int _p, int _s) {
        i = _i;
        j = _j;
        p = _p;
        s = _s;
    }
};

vvvi dist;
char mp[5000][5000];
queue<cell_st> q;

void add_cell_st(cell_st s, int d) {
    if(dist[s.i][s.j][s.p] == INF or s.s > 0) {
        dist[s.i][s.j][s.p] = d;
        q.push(s);
    }
}

int r, c, k;

void visit_cell(int i, int j, int p, int d, bool nodoor) {
    if(i < 0 or i >= r or j < 0 or j >= c or (nodoor and mp[i][j] == 2)) {
        
    }
    else {
        add_cell_st(cell_st(i, j, p, 0), d);
    }
}

void visit_near(cell_st s, int d) {
    visit_cell(s.i-1, s.j, s.p, d, (k==1 and mp[s.i][s.j] == 2));
    visit_cell(s.i+1, s.j, s.p, d, (k==1 and mp[s.i][s.j] == 2));
    visit_cell(s.i, s.j-1, s.p, d, (k==1 and mp[s.i][s.j] == 2));
    visit_cell(s.i, s.j+1, s.p, d, (k==1 and mp[s.i][s.j] == 2));
}



int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        
        cin >> r >> c >> k;
        int is;
        int js;
        int ib;
        int jb;
        for(int i=0; i < r; ++i) {
            string s;
            cin >> s;
            for(int j=0; j < c; ++j) {
                if(s[j] == '#') mp[i][j] = 1;
                else if(s[j] == 'D') mp[i][j] = 2;
                else mp[i][j] = 0;
                if(s[j] == 'A') {
                    is = i;
                    js = j;
                }
                else if(s[j] == 'B') {
                    ib = i;
                    jb = j;
                }
                
            }
        }
            dist = vvvi(r, vvi(c, vi(k+1, INF)));
            dist[is][js][0] = 0;
            cell_st sti;
            sti.i = is;
            sti.j = js;
            sti.p = 0;
            sti.s = 0;
            q = queue<cell_st>();
            q.push(sti);
            int md = INF;
            while(!q.empty()) {
                cell_st s = q.front();
                q.pop();
                int d = dist[s.i][s.j][s.p]+1;
                if(s.i == ib and s.j == jb) {
                    md = d-1;
                    break;
                }
                if(mp[s.i][s.j] == 1) {
                    
                }
                else if(mp[s.i][s.j] == 2) {
                    if(s.s == 0) {
                        if(s.p < k) add_cell_st(cell_st(s.i, s.j, s.p+1, s.s+1), d);
                    }
                    else if(s.s == 1) {
                        visit_near(s, d);
                        add_cell_st(cell_st(s.i, s.j, s.p-1, s.s+1), d);
                    }
                    else if(s.s == 2) {
                        visit_near(s, d);
                    }
                }
                else {
                    visit_near(s, d);
                }
            }
            
            if(md == INF) {
                cout << "HAHAHUHU\n";
            }
            else {
                cout << md << '\n';
            }
            
        }
    }
