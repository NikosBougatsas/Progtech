#include <iostream>
#include <stdexcept>

using namespace std;

class my_vector {
  private:
    int *arr;
    int size;
  public:
    my_vector(const int a, const int &s) {
      size = s;
      arr = new int[size];
      for (int i = 0; i < s; ++i) {
        *(arr + i) = a;
      }
    }
    my_vector(const int &s) {
      size = s;
      arr = new int[size];
      for (int i = 0; i < size; ++i) {
        *(arr + i) = 0;
      }
    }
    ~my_vector() {
      delete [] arr;
    }
    const my_vector& operator = (const my_vector &v) {
      size = v.size;
      delete [] arr;
      arr = new int[size];
      for (int i = 0; i < size; ++i) {
        *(arr + i) = v[i];
      }
      return *this;
    }
    friend my_vector operator + (const my_vector &v1, const my_vector &v2) throw(logic_error){
      if (v1.size != v2.size) throw logic_error("incompatible sizes!");
      my_vector res(0, v1.size);
      for (int i = 0; i < v1.size; ++i) {
        res[i] = v1[i] + v2[i];
      }
      return res;
    }
    int &operator [] (int i) throw(logic_error) {
      if (i >= size) throw logic_error("out of bounds!");
      return arr[i];
    }
    int operator [] (int i) const throw(logic_error) {
      if (i >= size) throw logic_error("out of bounds!");
      return arr[i];
    }
    friend ostream& operator << (ostream &out, const my_vector &v) {
      out << v[0];
      for (int i = 1; i < v.size; ++i) {
        out << " " << v[i];
      }
      out << endl;
      return out;
    }
};

int main() {
  my_vector a(5, 10), b(6, 12), c(7, 10);
  a[6] = 9;
  cout << "Array a + c: " << a + c << endl;
  cout << "element a[6]: " << a[6] << endl;
  my_vector d = a + b; //Exception 1
  cout << a[12]; //Exception 2
}
