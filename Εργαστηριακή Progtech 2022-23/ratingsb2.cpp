#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

typedef map<string, string> genreMap;
typedef map<string, pair<int, int>> genreRatings;

bool more1 (const pair<string, int> &p1, const pair<string, int> &p2) {
  if (p1.second == p2.second) return p1.first < p2.first;
  return p1.second > p2.second;
}

int main() {
  int N, k, G;
  string s, t;
  genreMap gM;
  genreRatings gR;
  set<string> genreList;
  vector<pair<string, int>> v;
  cin >> N >> G;
  for (int i = 0; i < N; ++i) {
    cin >> s >> t;
    gM[s] = t;
    genreList.insert(t);
  }
  while (cin >> s >> t >> k) {
    if (k >= 0 && k <= 100) {
      string l;
      l = gM[s];
      gR[l].first++;
      gR[l].second += k;
    }
  }
  for (auto it: genreList) {
    pair<string, int> p;
    p.first = it;
    p.second = gR[it].second/gR[it].first;
    v.push_back(p);
  }
  sort(v.begin(), v.end(), more1);
  if (G > genreList.size()) {
    G = genreList.size();
  }
  for (int i = 0; i < G; ++i) {
    cout << v[i].first << " " << v[i].second << endl;
  }
}
