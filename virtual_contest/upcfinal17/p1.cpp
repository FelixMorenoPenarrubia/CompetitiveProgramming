#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    
    vector<int> mapa (101);
    for(int i=1; i <= 100; ++i) {
        mapa[i] = i;
    }
    
    mapa[2] = 38;
    mapa[7] = 14;
    mapa[8] = 31;
    mapa[15] = 26;
    mapa[21] = 42;
    mapa[28] = 84;
    mapa[36] = 44;
    mapa[51] = 67;
    mapa[78] = 98;
    mapa[71] = 91;
    mapa[87] = 94;
    
    mapa[16] = 6;
    mapa[46] = 25;
    mapa[49] = 11;
    mapa[62] = 19;
    mapa[64] = 60;
    mapa[74] = 53;
    mapa[89] = 68;
    mapa[95] = 75;
    mapa[92] = 88;
    mapa[99] = 80;
    
    int T;
   // cin >> T;
    ll n;
    while(cin >> n) {
       /* ll n; 
        cin >> n;*/
        vector<ll> r(n);
        for(int i=0; i < n; ++i) cin >> r[i];
        ll cnt = 1;
        ll cnt2 = 0;
        ll red = 1;
        ll blue = 1;
        while(cnt2 >= 0) {
            if(cnt%2) {
                red += r[(cnt2)%n];
                if(red == 100) break;
                if(red > 100) red = 200-red;
                if(r[(cnt2)%n] == 6) --cnt;
                red = mapa[red];
            }
            else {
                blue += r[(cnt2)%n];
                if(blue == 100) break;
                if(blue > 100) blue = 200-blue;
                if(r[(cnt2)%n] == 6) --cnt;
                blue = mapa[blue];
            }
            ++cnt;
            ++cnt2;
            cnt2 %= n;
            cnt += 2;
            cnt %= 2;
        }
        cout << (cnt%2 ? "RED" : "BLUE") << endl;
    }
}
