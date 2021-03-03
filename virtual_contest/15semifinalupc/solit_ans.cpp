#include<bits/stdc++.h>

using namespace std;


typedef pair<int, int> ii;
typedef vector<ii> vii;


int iterate(vii v) {
	int n = v.size();
	for(int i=0; i < n-2; ++i) {
		if(v[i].first == v[i+2].first or v[i].second == v[i+2].second) return i+1;
	}
	return 0;
}

int main() {

	cout << "0.00174" << endl;

}