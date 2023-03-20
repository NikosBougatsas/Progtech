#include <iostream>

using namespace std;

template <typename T>

class stack {
  public:
    stack (int size) {
      data = new T[size];
      top = 0;
      sizea = size;
    };

    stack (const stack &s) {
      top = s.top;
      sizea = s.sizea;
      data = new T[sizea];

      for (int i = 0; i < top; i++) {
        data[i] = s.data[i];
      }
    };

    ~stack () {
      delete [] data;
    };

    const stack & operator = (const stack &s) {
      top = s.top;
      sizea = s.sizea;
      delete [] data;
      data = new T [sizea];

      for (int i = 0; i < top; i++) {
        data[i] = s.data[i];
      }
      return *this;
    };

    bool empty () {
      return top == 0;
    };

    void push (const T &x) {
      data[top] = x;
      top++;
    };

    T pop () {
      return data[--top];
    };

    int size () {
      return top;
    };

    friend ostream & operator << (ostream &out, const stack &s) {
      out << "[";

      if (s.top != 0) {
        for (int i = 0; i < s.top - 1; i++) {
          out << s.data[i] << ", ";
        }
        out << s.data[s.top - 1] << "]";
      }
      else {
        out << "]";
      }
      return out;
    };

  private:
    int top, sizea;
    T *data;
};

#ifndef CONTEST
int main() {
  //ints
  stack<int> s(10);
  cout << "s is empty: " << s << endl;
  s.push(42);
  cout << "s has one element: " << s << endl;
  s.push(17);
  s.push(34);
  cout << "s has more elements: " << s << endl;
  cout << "How many? " << s.size() << endl;
  stack<int> t(5);
  t.push(7);
  cout << "t: " << t << endl;
  t = s;
  cout << "popping from s: " << s.pop() << endl;
  s.push(8);
  stack<int> a(s);
  t.push(99);
  a.push(77);
  cout << "s: " << s << endl;
  cout << "t: " << t << endl;
  cout << "a: " << a << endl;
  //doubles
  stack<double> c(4);
  c.push(3.14);
  c.push(1.414);
  cout << "c contains doubles " << c << endl;
  //and with chars
  stack<char> k(4);
  k.push('$');
  cout << "k contains a character " << k << endl;

  return 0;
}
#endif
