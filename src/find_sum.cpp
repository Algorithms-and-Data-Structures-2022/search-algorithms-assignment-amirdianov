#include "assignment/find_sum.hpp"  // find_elements

namespace assignment {

  std::optional<std::pair<int, int>> find_sum(const std::vector<int>& data, int sum) {

    // Tips: для создания пары (pair) используйте функцию std::make_pair
    int ind_l = 0;
    int ind_r = data.size() - 1;
    auto pair = std::make_pair(ind_l, ind_r);
    int summa = data[ind_l] + data[ind_r];
    while (ind_l <= ind_r) {
      if (summa > sum) {
        ind_r -= 1;
      }
      if (summa < sum) {
        ind_l += 1;
      }
      if (summa == sum) {
        return pair;
      }
      pair = std::make_pair(ind_l, ind_r);
      summa = data[ind_l] + data[ind_r];
    }
    return std::nullopt;
  }

}  // namespace assignment