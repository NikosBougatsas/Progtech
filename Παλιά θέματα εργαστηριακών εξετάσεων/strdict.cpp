#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef map<int, set<string>> dict;

int main() {
  int N, D, d, max = 0, pos = 0;
  string w;
  dict m;
  set<string> s;
  cin >> N >> D;
  vector<int> v(D, 0);

  for (int i = 0; i < N; ++i) {
    cin >> d >> w;
    v[d-1]++;
    m[d-1].insert(w);
  }
  for (int i = 0; i < D; ++i) {
    if ((m[i].size() > max) || ((m[i].size() == max) && (v[i] < max))) {
      max = m[i].size();
      pos = i;
    }
  }
  cout << "largest dictionary is " << pos + 1 << " with " << m[pos].size() << " word(s)" << endl;
  bool flag = true;
  for (auto it: m[0]) {
    for (int i = 1; i < D; ++i) {
      if (m[i].find(it) == m[i].end()) {
        flag = false; break;
      }
    }
    if (flag) {
      s.insert(it);
    }
    flag = true;
  }
  for (auto it: s) {
    cout << it << endl;
  }
  cout << s.size() << " word(s) appear in all dictionaries" << endl;
}
