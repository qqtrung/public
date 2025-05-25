#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

void build(int parent, int child, char c, Node *&root) {
  if (root == NULL)
    return;
  if (root->data == parent) {
    if (c == 'L')
      root->left = new Node(child);
    if (c == 'R')
      root->right = new Node(child);
    return;
  }
  build(parent, child, c, root->left);
  build(parent, child, c, root->right);
}

Node *createBST(int a[], int start, int end) {
  if (start > end)
    return NULL;
  int mid = (start + end) / 2;
  Node *root = new Node(a[mid]);
  root->left = createBST(a, start, mid - 1);
  root->right = createBST(a, mid + 1, end);
  return root;
}

void insert(Node *&root, int x) {
  if (root == NULL) {
    root = new Node(x);
    return;
  }
  if (root->data > x)
    insert(root->left, x);
  if (root->data < x)
    insert(root->right, x);
}

void postOrder(Node *&root) {
  if (root == NULL)
    return;
  if (root->left)
    postOrder(root->left);
  if (root->right)
    postOrder(root->right);
  cout << root->data << ' ';
}

void preOrder(Node *&root) {
  if (root == NULL)
    return;
  cout << root->data << ' ';
  if (root->left)
    preOrder(root->left);
  if (root->right)
    preOrder(root->right);
}

void inOrder(Node *&root) {
  if (root == NULL)
    return;
  if (root->left)
    inOrder(root->left);
  cout << root->data << ' ';
  if (root->right)
    inOrder(root->right);
}

void Right_Level_Oder(Node *root) {
  queue<Node *> q;
  q.push(root);
  while (q.size()) {
    Node *root = q.front();
    q.pop();
    cout << root->data << ' ';
    if (root->right != NULL)
      q.push(root->right);
    if (root->left != NULL)
      q.push(root->left);
  }
}

void deleteNode(Node *&root, int val) {
  if (root == NULL) {
    cout << "Not Found\n";
    return;
  }
  if (root->data > val) {
    deleteNode(root->left, val);
  } else if (root->data < val) {
    deleteNode(root->right, val);
  } else {
    if (root->right == NULL) {
      root = root->left;
    } else {
      if (root->right->left == NULL) {
        Node *tmp = root;
        root = tmp->right;
        root->left = tmp->left;
      } else {
        Node *root_right = root->right;
        Node *root_right_left = root_right->left;
        while (root_right_left->left != NULL) {
          root_right_left = root_right_left->left;
          root_right = root_right->left;
        }
        root->data = root_right_left->data;
        root_right->left = NULL;
      }
    }
  }
}

int main() {
  string a;
  Node *root = NULL;
  while (getline(cin, a)) {
    vector<string> q;
    stringstream ss(a);
    string tmp;
    while (ss >> a) {
      q.push_back(a);
    }
    if (q[0] == "1") {
      cout << "insert: " << q[1] << '\n';
      insert(root, stoi(q[1]));
    } else if (q[0] == "2") {
      cout << "delete: " << q[1] << '\n';
      deleteNode(root, stoi(q[1]));
    } else if (q[0] == "3") {
      cout << "pre: ";
      preOrder(root);
      cout << '\n';
    } else if (q[0] == "4") {
      cout << "in: ";
      inOrder(root);
      cout << '\n';
    } else if (q[0] == "5") {
      cout << "post: ";
      postOrder(root);
      cout << '\n';
    }
  }
  return 0;
}
