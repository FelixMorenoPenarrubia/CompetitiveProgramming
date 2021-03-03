#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;





int main() {
    int n;
    cin >> n;
    cout << 6 << endl;
    if(n%2) {
        for(int i=0; i < n-1; ++i) {
            if(i > 0) cout << " ";
            cout << i+1;
        }
        cout << " " << 2*n-2;
        cout << endl;
        for(int i=0; i < n-2; ++i) {
            if(i > 0) cout << " ";
            cout << n+i;
        }
        cout << " " << 2*n-2 << " " << 2*n-1;
        cout << endl;
        for(int i=0; i < n-2; ++i) {
            if(i > 0) cout << " ";
            cout << n/2+i+1;
        }
        cout << " " << 2*n-1 << " " << 2*n;
        cout << endl;
        for(int i=0; i < n-1; ++i) {
            if(i > 0) cout << " ";
            cout << (n+n/2+i-2)%(2*n-3)+1;
        }
         cout << " " << 2*n-1;
        cout << endl;
        for(int i=0; i < n/2; ++i) {
            if(i > 0) cout << " ";
            cout << i+1;
        }
        for(int i=0; i < n/2-1; ++i) {
            if(i > -1) cout << " ";
            cout << n+i;
        }
        cout << " " << 2*n-2 << " " << 2*n;
        cout << endl;
        for(int i=0; i < n/2; ++i) {
            if(i > 0) cout << " ";
            cout << n/2+i+1;
        }
        for(int i=0; i < n/2; ++i) {
            if(i > -1) cout << " ";
            cout << n+n/2+i-1;
        }
        cout << " " << 2*n;
        cout << endl;
    }
    else {
        for(int i=0; i < n; ++i) {
            if(i > 0) cout << " ";
            cout << i+1;
        }
        cout << endl;
        for(int i=0; i < n; ++i) {
            if(i > 0) cout << " ";
            cout << n+i+1;
        }
        cout << endl;
        for(int i=0; i < n; ++i) {
            if(i > 0) cout << " ";
            cout << n/2+i+1;
        }
        cout << endl;
        for(int i=0; i < n; ++i) {
            if(i > 0) cout << " ";
            cout << (n+n/2+i)%(2*n)+1;
        }
        cout << endl;
        for(int i=0; i < n/2; ++i) {
            if(i > 0) cout << " ";
            cout << i+1;
        }
        for(int i=0; i < n/2; ++i) {
            if(i > -1) cout << " ";
            cout << n+i+1;
        }
        cout << endl;
        for(int i=0; i < n/2; ++i) {
            if(i > 0) cout << " ";
            cout << n/2+i+1;
        }
        for(int i=0; i < n/2; ++i) {
            if(i > -1) cout << " ";
            cout << n+n/2+i+1;
        }
        cout << endl;
    }
}
