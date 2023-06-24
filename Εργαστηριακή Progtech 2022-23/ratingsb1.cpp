#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef map<string, vector<string>> viewerInfo;

bool more1 (const pair<string, int> &p1, const pair<string, int> &p2) {
  if (p1.second == p2.second) return p1.first < p2.first;
  return p1.second > p2.second;
}

int main() {
  string s, t;
  int n, K;
  viewerInfo vI;
  set<string> viewers;
  vector<pair<string, int>> v;
  cin >> K;

  while (cin >> s >> t >> n) {
    if (n>=0 && n <=100) {
    vI[t].push_back(s);
    viewers.insert(t);
    }
  }
  for (auto it: viewers) {
    pair<string, int> p;
    p = make_pair(it, vI[it].size());
    v.push_back(p);
  }
  sort(v.begin(), v.end(), more1);
  for (int i = 0; i < K; ++i) {
    cout << v[i].first << " " << v[i].second << endl;
  }
}
