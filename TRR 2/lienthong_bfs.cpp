#include <bits/stdc++.h>
using namespace std;

int n;
int a[110][110];
int vs[110] = {};
vector<vector<int>> ans;

void BFS(int u, vector<int>& vt) {
  queue<int> q;
  q.push(u);
  vs[u] = 1;
  while (!q.empty()) {
    int u = q.front();
    vt.push_back(u);
    q.pop();
    for (int v = 1; v <= n; v++) {
      if (v != u && !vs[v] && a[u][v]) {
        vs[v] = 1;
        q.push(v);
      }
    }
  }
}

void nhap() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vs[i]) {
      vector<int> vt;
      BFS(i, vt);
      sort(vt.begin(), vt.end());
      ans.push_back(vt);
    }
  }
  cout << ans.size() << '\n';
  for (auto v : ans) {
    for (int i : v) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}

int main() {
  nhap();
  return 0;
}

