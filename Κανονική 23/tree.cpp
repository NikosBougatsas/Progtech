template<typename T>

struct node {
  T data;
  node *left, *right;
};

int freq (node *t, const T &x, int h) {
  if (t == NULL) return 0;
  if (h == 1){
    if (t->data == x) return 1;
    else return 0;
  }
  else if (h > 1)
    return freq(t->left, x, h-1) + freq(t->right, x, h-1);
}
