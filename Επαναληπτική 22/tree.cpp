//Θέμα 3 επαναληπτική 22 (με επιφύλαξη για την συντακτική ορθότητα)
struct node {
  int data;
  node *left, *right;
};

bool func (node *root, const int &k) {
  if (root == NULL) return false;
  bool flag = false;
  f_help(root, k, flag, root->data);
  return flag;
}

void f_help (node *n, const int &k, bool &f, int &count) {
  if (count == k) f = true; return;
  else if (count > k) return;
  else {
    if (n->left != NULL) {
      f_help(n->left, k, f, count + (n->left)->data);
    }
    if (n->right != NULL) {
      f_help(n->right, k, f, count + (n->right)->data);
    }
    return;
  }
}
