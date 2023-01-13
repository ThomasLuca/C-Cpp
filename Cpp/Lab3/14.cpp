#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

int main() {
  map<char, unordered_set<string>> m;
  string word;
  cout << "geef woorden, eindig met STOP" << endl;
  cin >> word;

  while(word!="STOP") {
    m[word[0]].insert(word);
    cin >> word;
  }
  cout << "Letter: ";
  char letter;
  cin >> letter;

  if(m.count(letter) > 0) {
   cout << "There are " << m[letter].size() << " words that start with char" << endl;
  }

  return 0;
}
