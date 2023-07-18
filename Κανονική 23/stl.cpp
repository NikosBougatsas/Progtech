#include <iostream>
#include <string>
#include <set>
#include <map>
#include <fstream>

using namespace std;

int main() {
  string s;
  set<string> s1;
  map<string, int> m;
  int count = 0;

  ifstream input1("words.txt");
  while (cin >> s) {
    s1.insert(s);
  }
  input1.close();

  ifstream input2("input.txt");
  while (cin >> s) {
    if (s1.find(s) != s1.end()) {
      m[s]++;
    }
    else count++;
  }
  input2.close();

  for (auto it: s1) {
    if (m[it] != 0) {
      cout << it << " " << m[it] << endl;
    }
  }
  cout << count << endl;
}
