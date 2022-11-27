#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  for (auto it = v.rbegin(); it != v.rend(); ++it)
    out << *it << " ";
  return out;
}
