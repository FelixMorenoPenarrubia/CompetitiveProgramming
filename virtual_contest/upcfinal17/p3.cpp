#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    double l1, l2, p1, p2;
    cout.setf(ios::fixed);
    cout.precision(3);
    while(cin >> l1 >> l2 >> p1 >> p2) {
        double p3 = 1-p1-p2;
        cout << 5*(p1+2*(p2)+3*(p3))/(p2*l1+(1-p1-p2)*l2) << endl;
    }
}
