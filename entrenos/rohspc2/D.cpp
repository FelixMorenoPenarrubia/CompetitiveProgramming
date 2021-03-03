#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;


struct sector {
    int x1, y1, x2, y2;
    sector() {}
    sector(int _x1, int _y1, int _x2, int _y2) {
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    
    vi beg(m);
    vi end(m);
    vector<sector> sec;
    sec.push_back(sector(0, 0, m-1, n-1));
    for(int z=0; z < 10; ++z) {
        string q = "";
        for(int i=0; i < (int)sec.size(); ++i) {
            sector s = sec[i];
            
           // cerr << "i = " << i << endl;
           // cerr << s.x1 << " " << s.y1 << " / " << s.x2 << " " << s.y2 << endl;
            
            if(s.x2-s.x1 > 0) {
                int d = s.x2-s.x1;
                q += string(d/2, 'D');
                q += string(s.y2-s.y1, 'R');
                q += string(d - d/2, 'D');
            }
            else {
                q += string(s.y2-s.y1, 'R');
            }
            if(i != (int)sec.size() -1) q += 'D';
        }
        cout << "? " << q << endl;
        int t;
        cin >> t;
        vi x(t);
        vi y(t);
        for(int i=0; i < t; ++i) {
            cin >> x[i] >> y[i];
            x[i]--;
            y[i]--;
        }
        vector<sector> nsec;
        int idx = 0;
        for(int i=0; i < (int)sec.size(); ++i) {
            sector s = sec[i];
            if(s.x2-s.x1 > 0) {
                int d = s.x2-s.x1;
                int p = s.x1+d/2;
                
             //   cerr << "i = " << i << " p = " << p << endl;
                
                while(x[idx] != p) idx++;
                beg[p] = y[idx];
                
             //   cerr << idx << endl;
                
                while(x[idx] == p) idx++;
                end[p] = y[idx-1];
                
               // cerr << idx << endl;
                
                sector ns1 = sector(s.x1, s.y1, p-1, beg[p]);
                sector ns2 = sector(p, beg[p], p, end[p]);
                sector ns3 = sector(p+1, end[p], s.x2, s.y2);
                
                if(ns1.x1 <= ns1.x2) nsec.push_back(ns1);
                nsec.push_back(ns2);
                if(ns3.x1 <= ns3.x2) nsec.push_back(ns3);
            }
            else {
                nsec.push_back(s);
                beg[s.x1] = s.y1;
                end[s.x1] = s.y2;
            }
        }
        sec = nsec;
        
    }
    string s;
    for(int i=0; i < m; ++i) {
        s += string(end[i]-beg[i], 'R');
        if(i != m-1) s += 'D';
    }
    cout << "! " << s << endl;
}
