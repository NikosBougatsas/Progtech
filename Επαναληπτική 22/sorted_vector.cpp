#include <iostream>

using namespace std;

template<typename T>
class sorted_vector {
  private:
    T sum;
    struct node {
      node *next;
      T data;
    };
    node *head;
  public:
    sorted_vector() {head = NULL;}

    T getSum() {
      return sum;
    }

    void insert(const T &key) {
      if (head == NULL) {
        head = new node;
        head->data = key;
        head->next = NULL;
        sum = key;
        return;
      }
      else {
        if (head->data > key) {
          sum += key;
          node *q = new node;
          node *p = head;
          q->data = key;
          q->next = p;
          head = q;
        }
        else {
          node *n = head;
          while (n->data < key && n->next != NULL) {
            n = n->next;
          }
          node *q = new node;
          q->data = key;
          if (n->next != NULL) {
            q->next = n->next;
          }
          else {
            q->next = NULL;
          }
          n->next = q;
          sum += key;
        }
      }
    }

    const T operator [] (const int &x) {
      node *n = head;
      for (int i = 0; i < x; ++i) {
        n = n->next;
      }
      return n->data;
    }

    sorted_vector operator + (const sorted_vector &s1) {
      sorted_vector sv;
      node *n = head, *p = s1.head;
      while (n != NULL && p != NULL) {
        sv.insert(n->data + p->data);
        n = n->next; p = p->next;
      }
      return sv;
    }

    friend ostream& operator << (ostream &out, const sorted_vector &sv) {
      node *n = sv.head;
      while (n != NULL) {
        out << n->data << " ";
        n = n->next;
      }
      out << endl << "Sum: " << sv.sum << endl;
      return out;
    }
};
