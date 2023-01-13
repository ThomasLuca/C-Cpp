#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_set>

template <typename T> void print(const std::vector<T> &v) {
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  for (int i = 0; i < v.size(); i++) {
    out << v[i] << " ";
  }
  std::cout << std::endl;
  return out;
}

inline std::ostream &operator<<(std::ostream &out, const std::unordered_set<std::basic_string<char>> &us) {
  for (auto &e: us) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  return out;
}

template <typename S, typename D>
std::ostream &operator<<(std::ostream &out, const std::map<S, D> &m) {
  typename std::map<S, D>::const_iterator it = m.begin();
  while (it != m.end()) {
    out << "  " << it->first << " --> " << it->second << std::endl;
    it++;
  }
  return out;
}
