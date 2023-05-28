#include <iostream>
#include <tuple>
#include <algorithm>
#include <string>

using namespace std;

typedef tuple<int, string, string, int, int> employee;

bool less1(const employee &e1, const employee &e2) {
  return get<0>(e1) < get<0>(e2);
}
bool more1(const employee &e1, const employee &e2) {
  return get<0>(e1) > get<0>(e2);
}
bool less2(const employee &e1, const employee &e2) {
  if (get<1>(e1) == get<1>(e2)) return less1(e1, e2);
  return get<1>(e1) < get<1>(e2);
}
bool more2(const employee &e1, const employee &e2) {
  if (get<1>(e1) == get<1>(e2)) return less1(e1, e2);
  return get<1>(e1) > get<1>(e2);
}
bool less3(const employee &e1, const employee &e2) {
  if (get<2>(e1) == get<2>(e2)) return less2(e1, e2);
  return get<2>(e1) < get<2>(e2);
}
bool more3(const employee &e1, const employee &e2) {
  if (get<2>(e1) == get<2>(e2)) return more2(e1, e2);
  return get<2>(e1) > get<2>(e2);
}
bool less4(const employee &e1, const employee &e2) {
  if (get<3>(e1) == get<3>(e2)) return less1(e1, e2);
  return get<3>(e1) < get<3>(e2);
}
bool more4(const employee &e1, const employee &e2) {
  if (get<3>(e1) == get<3>(e2)) return less1(e1, e2);
  return get<3>(e1) > get<3>(e2);
}
bool less5(const employee &e1, const employee &e2) {
  if (get<4>(e1) == get<4>(e2)) return less1(e1, e2);
  return get<4>(e1) < get<4>(e2);
}
bool more5(const employee &e1, const employee &e2) {
  if (get<4>(e1) == get<4>(e2)) return less1(e1, e2);
  return get<4>(e1) > get<4>(e2);
}
ostream & operator << (ostream &out, const employee &e) {
  out << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << " " << get<3>(e) << " " << get<4>(e) << endl;
  return out;
}
int main() {
  int N, M, id, year, salary;
  string name, surname;
  cin >> N;
  vector<employee> v;

  for (int i = 0; i < N; ++i) {
    cin >> id >> name >> surname >> year >> salary;
    v.push_back(make_tuple(id, name, surname, year, salary));
  }
  cin >> M;

  for (int i = 0; i < M; ++i) {
    string what, order;
    int item;
    cin >> what >> order >> item;
    if (what == "id") {
      if (order == "asc") {
        sort(v.begin(), v.end(), less1);
      }
      else {
        sort(v.begin(), v.end(), more1);
      }
    }
    if (what == "name") {
      if (order == "asc") {
        sort(v.begin(), v.end(), less3);
      }
      else {
        sort(v.begin(), v.end(), more3);
      }
    }
    if (what == "year") {
      if (order == "asc") {
        sort(v.begin(), v.end(), less4);
      }
      else {
        sort(v.begin(), v.end(), more4);
      }
    }
    if (what == "salary") {
      if (order == "asc") {
        sort(v.begin(), v.end(), less5);
      }
      else {
        sort(v.begin(), v.end(), more5);
      }
    }
    cout << "Query: " << what << " " << order << " " << item << endl;
    vector<employee>::iterator it;
    for (it = v.begin(); it != v.begin() + item; ++it) {
      cout << *it;
    }
  }
}
