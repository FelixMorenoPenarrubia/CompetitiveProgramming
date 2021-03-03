#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("folding.in", "r", stdin);
    freopen("folding.out", "w", stdout);
    double W, H, w, h;
    cin >> W >> H >> w >> h;
    double orW, orH;
    orW = W;
    orH = H;
    
    int ans1 = 0;
    if(w > W or h > H) {
        ans1 = 1e9;
        
    }
    else {
        while(W > w) {
            double d = W/2;
            //if(W%2) d++;
            W = max(w, d);
            ans1++;
        }
        while(H > h) {
            double d = H/2;
            //if(H%2) d++;
            H = max(h, d);
            ans1++;
        }
    }
    W = orW;
    H = orH;
    swap(W, H);
    
    int ans2 = 0;
    if(w > W or h > H) {
        ans2 = 1e9;
        
    }
    else {
        while(W > w) {
            double d = W/2;
            //if(W%2) d++;
            W = max(w, d);
            ans2++;
        }
        while(H > h) {
            double d = H/2;
            //if(H%2) d++;
            H = max(h, d);
            ans2++;
        }
    }
    if(min(ans1, ans2) == 1e9) {
        cout << -1 << endl;
    }
    else cout << min(ans1, ans2) << endl;
}
