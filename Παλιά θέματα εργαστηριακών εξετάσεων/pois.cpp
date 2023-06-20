#include <iostream>
#include <tuple>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
typedef map<int, tuple<string, double, double>> poiMap;
typedef map<int, map<string, vector<double>>> distanceMap;

double distance (const double &x1, const double &y1, const double &x2, const double &y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
  int N, K;
  double x, y;
  distanceMap dM;
  poiMap pM;
  tuple<string, double, double> t;
  string s;
  set<string> ss;
  pair<double, double> p;
  vector<pair<double, double>> v;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> x >> y >> s;
    t = make_tuple(s, x, y);
    pM[i] = t;
    ss.insert(s);
  }
  cin >> K;
  for (int i = 0; i < K; ++i) {
    cin >> x >> y;
    p = make_pair(x, y);
    v.push_back(p);
    for (int j = 0; j < N; ++j) {
      dM[i][get<0>(pM[j])].push_back(distance(x, y, get<1>(pM[j]), get<2>(pM[j])));
    }
  }
  for (int i = 0; i < K; ++i) {
    cout << fixed << setprecision(0) << v[i].first << " " << v[i].second << endl;
    for (auto it: ss) {
      sort(dM[i][it].begin(), dM[i][it].end());
      cout << "  " << it << " " << fixed << setprecision(3) << dM[i][it][0] << endl;
    }
  }
}
