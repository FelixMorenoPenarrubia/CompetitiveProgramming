#include "meetings.h"

std::vector<long long> minimum_costs(std::vector<int> H, std::vector<int> L,
                                     std::vector<int> R) {
  int Q = L.size();
  std::vector<long long> C(Q);
  for (int j = 0; j < Q; ++j) {
    C[j] = H[L[j]];
  }
  return C;
}
