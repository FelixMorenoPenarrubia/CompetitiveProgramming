// name = molecules_iz_rand.cpp, type = cpp.g++11

#include "molecules.h"
//#include "molecules.h"

#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

std::vector<int> find_subset(int l, int u, std::vector<int> w) {
    double start = clock() / (double)CLOCKS_PER_SEC;
    int n = w.size();
    long long mx = 0;
    for (int x : w) mx += x;
    if (mx < l) return vector<int>();
    while (true) {
        double cur = clock() / (double)CLOCKS_PER_SEC;
        if (cur - start > 0.85) {
            return vector<int>();
        }
        vector<char> was(n, 0);
        long long sum = 0;
        while (sum < l) {
            int x = rand() % n;
            if (!was[x]) {
                was[x] = 1;
                sum += w[x];
            }
        }
        if (sum <= u) {
            vector<int> ans;
            for (int i = 0; i < n; i++) if (was[i]) ans.push_back(i);
            return ans;
        }
    }
}

int main() {
    int n, l, u;
    scanf("%d %d %d", &n, &l, &u);
    std::vector<int> w(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    std::vector<int> result = find_subset(l, u, w);
    
    // BEGIN SECRET
    puts("14e047d7a2907b9034950b074822b302");
    // END SECRET
    
    printf("%d\n", (int)result.size());
    for (int i = 0; i < (int)result.size(); i++)
        printf("%d%c", result[i], " \n"[i == (int)result.size() - 1]);
}

