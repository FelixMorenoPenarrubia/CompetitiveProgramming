#include "highway.h"

void find_pair(int N, std::vector<int> U, std::vector<int> V, int A, int B) {
  int M = U.size();
  for (int j = 0; j < 50; ++j) {
    std::vector<int> w(M);
    for (int i = 0; i < M; ++i) {
      w[i] = 0;
    }
    long long toll = ask(w);
  }
  answer(0, N - 1);
}
