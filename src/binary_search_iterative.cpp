#include "assignment/binary_search_iterative.hpp"

namespace assignment {

  std::optional<int> BinarySearchIterative::Search(const std::vector<int>& data, int search_element) const {

    // Tips:
    // 1. Заведите две переменные: (а) индекс левой границы и (б) индекс правой границы.
    // 2. Поиск ведется пока индекс левой границы не превысил индекс правой.
    // 3. Каждую итерацию вычисляйте индекс середины внутри области, задаваемой индексами левой и правой границы.
    // 4. Рассмотрите 3 случая:
    //    1) Целевой элемент равен элементу посередине.
    //    2) Целевой элемент меньше элемента посередине (область поиска сокращается).
    //    3) Целевой элемент больше элемента посередине (область поиска сокращается).
    int ind_l = 0;
    int ind_r = data.size() - 1;
    int middle = (ind_r + ind_l) / 2;
    while (ind_l <= ind_r) {
      if (data[middle] == search_element) {
        return middle;
      }
      if (search_element < data[middle]) {
        ind_r = middle - 1;
      }
      if (search_element > data[middle]) {
        ind_l = middle + 1;
      }
      middle = (ind_r + ind_l) / 2;
    }
    return std::nullopt;
  }

}  // namespace assignment