#include <memory>
#include <vector>

template <typename T> class Doos {
public:
  Doos();
  Doos(const Doos<T> &);
  Doos<T> &operator=(const Doos<T> &);
  ~Doos();

private:
  int n;
  std::vector<T> b;

  Doos<T> *c;
  std::unique_ptr<std::string> *d;

  void copy(const Doos<T> &);
};
