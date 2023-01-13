#include "containers.h"
#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

using namespace std;

void print_woorden(const string &toFind,
                   const vector<map<char, unordered_set<string>>> &v) {
  if (toFind.size() >= v.size()) {
    cout << "Word not in container" << endl;
    return;
  }
  map<char, unordered_set<string>>::const_iterator it =
      v[toFind.size()].find(toFind[0]);
  if (it != v[toFind.size()].end()) {
    cout << it->second;
    return;
  }
  cout << "Word not in container" << endl;
}

int main() {
  vector<map<char, unordered_set<string>>> v(10);
  string word;
  cin >> word;
  while (word != "STOP") {
    if (word.size() > v.size() - 1)
      v.resize(word.size() + 1);
    v[word.size()][word[0]].insert(word);
    cin >> word;
  }

  print_woorden("foobas", v);

  return 0;
}
