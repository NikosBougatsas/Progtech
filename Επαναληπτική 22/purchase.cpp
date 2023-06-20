//Θέμα 2 επαναληπτική 2022
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef map<string, pair<int, int>> stuffMap;

int main() {
  int n, cost = 0;
  string s; vector<string> vs;
  stuffMap sM = {};

  while (cin >> s >> n) {
    int a = sM[s].first + 1;
    int b = sM[s].second + n;
    sM[s] = make_pair(a, b);
    if (find(vs.begin(), vs.end(), s) == vs.end()) {
      vs.push_back(s);
    }
    cost += n;
  }

  for (const auto &it: vs) {
    cout << it << " " << sM[it].first << " x ";
    cout << sM[it].second/sM[it].first << " = ";
    cout << sM[it].second << endl;
  }

  cout << "Total: " << cost << endl;
}
