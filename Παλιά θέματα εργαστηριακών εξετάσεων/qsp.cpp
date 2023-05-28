#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void showq (queue<int> Q) {
  queue<int> sq = Q;
  while (!sq.empty()) {
    cout << sq.front(); sq.pop();
    if (!sq.empty()) cout << " ";
  }
  cout << endl;
}

int main() {
  int N, n;
  cin >> N;
  queue<int> q;
  stack<int> s;
  string str;

  for (int i = 0; i < N; ++i) {
    cin >> n;
    q.push(n);
  }
  cin >> str;

  for (int i = 0; i < str.length(); ++i) {
    if (str[i] == 'P') {
      showq(q);
    }
    else if (str[i] == 'Q') {
      if (q.empty()) {
        cout << "error" << endl;
        return 0;
      }
      s.push(q.front());
      q.pop();
    }
    else if (str[i] == 'S') {
      if (s.empty()) {
        cout << "error" << endl;
        return 0;
      }
      q.push(s.top());
      s.pop();
    }
  }
}
