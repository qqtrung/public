#include <bits/stdc++.h>
using namespace std;

int n;
int a[110][110] = {};
int vs[110] = {};

int BFS(int u) {
  queue<int> q;
  q.push(u);
  vs[u] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 1; v <= n; ++v) {
      if (v != u && !vs[v] && a[u][v] == 1) {
        vs[v] = 1;
        q.push(v);
      }
    }
  }
  return 1;
}

int check() {
  memset(vs, 0, sizeof (vs));
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!vs[i]) {
      cnt += BFS(i);
    }
  }
  return cnt;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!vs[i]) {
      cnt += BFS(i);
    }
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i][j]) {
        a[i][j] = a[j][i] = 0;
        if (cnt < check()) ans.push_back({i, j});
        a[i][j] = a[j][i] = 1;
      }
    }
  }
  if (ans.size()) {
    cout << ans.size() << '\n';
    for (auto p : ans) {
      cout << p.first << ' ' << p.second << '\n';
    }
  } else {
    cout << 0;
  }
}

int main() {
  solve();
  return 0;
}
