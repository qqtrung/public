#include <bits/stdc++.h>
using namespace std;

vector<int> inOrder;
vector<int> levelOrder;
unordered_map<int, int> val_to_idx_inOrder;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

struct Info {
  Node *node;
  pair<int, int> left;
  pair<int, int> right;
  Info(Node *node, pair<int, int> left, pair<int, int> right) {
    this->node = node;
    this->left = left;
    this->right = right;
  }
};

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
  levelOrder.resize(n + 1);
  val_to_idx_inOrder.clear();

  for (int i = 1; i <= n; i++)
    cin >> inOrder[i];
  for (int i = 1; i <= n; i++)
    cin >> levelOrder[i];
  for (int i = 1; i <= n; i++)
    val_to_idx_inOrder[inOrder[i]] = i;

  Node *root = new Node(levelOrder[1]);

  int levelOrderIndex = 1;
  queue<Info> q;
  int idx_root = val_to_idx_inOrder[levelOrder[levelOrderIndex]];
  q.push(Info(root, make_pair(1, idx_root - 1), make_pair(idx_root + 1, n)));

  while (q.size()) {
    auto info = q.front();
    q.pop();

    int index_child_left_inOrder =
        val_to_idx_inOrder[levelOrder[levelOrderIndex + 1]];
    if (index_child_left_inOrder >= info.left.first &&
        index_child_left_inOrder <= info.left.second) {
      levelOrderIndex++;

      pair<int, int> child_left =
          make_pair(info.left.first, index_child_left_inOrder - 1);
      pair<int, int> child_right =
          make_pair(index_child_left_inOrder + 1, info.left.second);
      info.node->left = new Node(levelOrder[levelOrderIndex]);
      q.push(Info(info.node->left, child_left, child_right));
    }

    int index_child_right_inOrder =
        val_to_idx_inOrder[levelOrder[levelOrderIndex + 1]];
    if (index_child_right_inOrder >= info.right.first &&
        index_child_right_inOrder <= info.right.second) {
      levelOrderIndex++;

      pair<int, int> child_left =
          make_pair(info.right.first, index_child_right_inOrder - 1);
      pair<int, int> child_right =
          make_pair(index_child_right_inOrder + 1, info.right.second);
      info.node->right = new Node(levelOrder[levelOrderIndex]);
      q.push(Info(info.node->right, child_left, child_right));
    }
  }

  postOrder(root);
  cout << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
