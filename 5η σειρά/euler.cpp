#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
  int M, N, a, b, oddCount = 0;
  map<int, vector<int>> graph;
  set<int> vertexSet;
  set<int> oddVertexSet;
  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
    vertexSet.insert(a);
    vertexSet.insert(b);
  }
  for (auto it: vertexSet) {
    if ((graph[it].size()%2) != 0) {
      oddCount++;
      oddVertexSet.insert(it);
    }
  }
  if (oddCount == 0) {
    cout << "CYCLE" << endl;
  }
  else if (oddCount == 2) {
    cout << "PATH";
    for (auto it: oddVertexSet) {
      cout << " " << it;
    }
    cout << endl;
  }
  else {
    cout << "IMPOSSIBLE" << endl;
  }
}
