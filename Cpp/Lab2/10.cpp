#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template <typename T> void dupliceer(vector<unique_ptr<T>> &v, int n) {
  int original_size = v.size();
  v.reserve(v.size() * n);
}

int main() {
  unique_ptr<string> namen[] = {
      make_unique<string>("Rein"), make_unique<string>("Ada"),
      make_unique<string>("Eppo"), make_unique<string>("Pascal"),
      make_unique<string>("Ilse")};

  vector<unique_ptr<string>> namenvector;
  // voeg de unieke pointers van namen toe aan namenvector
  for (auto &naam : namen) {
    namenvector.push_back(move(naam));
  }
  // dupliceer(namenvector, 3);
  // print de inhoud van namenvector
  for (auto &name : namenvector) {
    cout << *name << " ";
  }
  
  cout << endl;
  // output moet zijn: Rein Rein Rein Ada Ada Ada Eppo Eppo Eppo Pascal Pascal
  // Pascal Ilse Ilse Ilse
}