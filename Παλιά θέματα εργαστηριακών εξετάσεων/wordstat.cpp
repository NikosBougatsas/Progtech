#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef map<string, vector<string>> text;
typedef map<string, int> wordCount;

bool less1 (const string &s1, const string &s2) {
  if (s1.length() == s2.length()) return s1 < s2;
  return s1.length() < s2.length();
}

bool more1 (const string &s1, const string &s2) {
  if (s1.length() == s2.length()) return s1 < s2;
  return s1.length() > s2.length();
}

int main() {
  string s, min, max, ab = "abcdefghijklmnopqrstuvwxyz";
  text t; wordCount wC;
  vector<pair<string, string>> v;
  for (int i = 0; i < 26; ++i) {
    wC[ab.substr(i, 1)] = 0;
  }
  while (cin >> s) {
    vector<string>::iterator i = find(t[s.substr(0, 1)].begin(), t[s.substr(0, 1)].end(), s);
    if (i == t[s.substr(0, 1)].end()) {
      t[s.substr(0, 1)].push_back(s);
    }
    wC[s.substr(0, 1)]++;
  }
  for (int i = 0; i < 26; ++i) {
    if (!t[ab.substr(i, 1)].empty()) {
      sort(t[ab.substr(i, 1)].begin(), t[ab.substr(i, 1)].end(), less1);
      min = t[ab.substr(i, 1)][0];
      sort(t[ab.substr(i, 1)].begin(), t[ab.substr(i, 1)].end(), more1);
      max = t[ab.substr(i, 1)][0];
      cout << ab.substr(i, 1) << ": " << wC[ab.substr(i, 1)] << " word(s), ";
      cout << t[ab.substr(i, 1)].size() << " unique word(s), longest '" << max;
      cout << "' and shortest '" << min << "'" << endl;
    }
  }
}
