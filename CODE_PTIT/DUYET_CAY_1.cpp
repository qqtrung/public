#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

vector<int> inOrder;
vector<int> preOrder;
unordered_map<int, int> val_to_idx_inOrder;

void build(int &preIndex, int idx_root_inOrder, Node *&root, int left,
           int right, string sign) {
  if (left > right)
    return;
  int idx_root_child_inOrder = val_to_idx_inOrder[preOrder[preIndex + 1]];
  if (idx_root_child_inOrder >= left && idx_root_child_inOrder <= right) {
    preIndex++;
    if (sign == "left") {
      root->left = new Node(inOrder[idx_root_child_inOrder]);
      build(preIndex, idx_root_child_inOrder, root->left, left,
            idx_root_child_inOrder - 1, "left");
      build(preIndex, idx_root_child_inOrder, root->left,
            idx_root_child_inOrder + 1, right, "right");
    } else if (sign == "right") {
      root->right = new Node(inOrder[idx_root_child_inOrder]);
      build(preIndex, idx_root_child_inOrder, root->right, left,
            idx_root_child_inOrder - 1, "left");
      build(preIndex, idx_root_child_inOrder, root->right,
            idx_root_child_inOrder + 1, right, "right");
    }
  }
}

void postOrder(Node *&root) {
  if (root == NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << ' ';
}

void solve() {
  int n;
  cin >> n;
  inOrder.resize(n + 1);
  preOrder.resize(n + 1);
  val_to_idx_inOrder.clear();

  for (int i = 1; i <= n; i++)
    cin >> inOrder[i];
  for (int i = 1; i <= n; i++)
    cin >> preOrder[i];
  for (int i = 1; i <= n; i++)
    val_to_idx_inOrder[inOrder[i]] = i;

  int idx_root_inOrder = val_to_idx_inOrder[preOrder[1]];
  Node *root = new Node(inOrder[idx_root_inOrder]);

  int preIndex = 1;
  build(preIndex, idx_root_inOrder, root, 1, idx_root_inOrder - 1, "left");
  build(preIndex, idx_root_inOrder, root, idx_root_inOrder + 1, n, "right");

  postOrder(root);

  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
