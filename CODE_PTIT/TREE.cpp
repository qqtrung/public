#include <bits/stdc++.h>
using namespace std;
int n, a[10005];
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
void build(int parent, int child, char c, Node* &root) {
    if (root == NULL) return;
    if (root->data == parent) {
        if (c == 'L') root->left = new Node(child);
        if (c == 'R') root->right = new Node(child);
        return;
    }
    build(parent, child, c, root->left);
    build(parent, child, c, root->right);
}
void insert(Node* &root, int x) {
    if (root == NULL) { root = new Node(x); return; }
    if (root->data > x) insert(root->left, x);
    if (root->data < x) insert(root->right, x);
}
void postOrder(Node* &root) {
    if (root==NULL) return;
    if (root->left) postOrder(root->left);
    if (root->right) postOrder(root->right);
    cout << root->data<< ' ';
}
void preOrder(Node* &root) {
    if (root==NULL) return;
    cout << root->data<< ' ';
    if (root->left) postOrder(root->left);
    if (root->right) postOrder(root->right);
}
void inOrder(Node* &root) {
    if (root==NULL) return;
    if (root->left) inOrder(root->left);
    cout << root->data<< ' ';
    if (root->right) inOrder(root->right);
}
void inOrder(int i) {
    if (i >= n) return;
    inOrder(2*i+1);
    cout << a[i] << ' ';
    inOrder(2*i+2);
}
void Right_Level_Oder(Node* root) {
    queue<Node*> q;
    q.push(root);
    while (q.size()) {
        Node* root = q.front(); q.pop();
        cout << root->data << ' ';
        if (root->right != NULL) q.push(root->right);
        if (root->left != NULL) q.push(root->left);
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        Node* root = NULL;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            insert(root, a[i]);
        }
        inOrder(root);
        cout << '\n';
    }
    return 0;
}

