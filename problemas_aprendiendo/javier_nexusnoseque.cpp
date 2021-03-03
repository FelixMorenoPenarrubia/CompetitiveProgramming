#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef  long double ld;
typedef vector<ld> vld;
typedef pair<ld, ld> dd;
typedef vector<dd> vdd;

ld EPS = 1e-12;
ld PI = 2*acos(0.0);


ld caso(int n) {
    vld angles;
    for(int i=0; i < n; ++i) {
        ld x, y;
        cin >> x >> y;
        ld alpha = atan2(x, y);
        if(x < 0) alpha += 2*PI;
        angles.push_back(alpha);
    }
    angles.push_back(0);
    sort(angles.begin(), angles.end());
    ld ans = angles[n];
    for(int i=0; i < n; ++i) {
        ans = min(ans, 2*angles[i]+2*PI-angles[i+1]);
    }
    for(int i=0; i < n; ++i) {
        ans = min(ans, 2*(2*PI-angles[n-i])+angles[n-i-1]);
    }
    return ans;
    
}


int main() {
    
    int n;
    cout.setf(ios::fixed);
    cout.precision(2);
    while(cin >> n and n != 0) {
        
        cout << (180.0/PI)*caso(n) << endl;
    }
}
