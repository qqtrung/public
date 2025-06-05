#include <bits/stdc++.h>
using namespace std;

int n;
int a[110][110];
int vs[110];
vector<int> vt;

int DFS(int u) {
  vs[u] = 1;
  for (int v = 1; v <= n; v++) {
    if (v != u && !vs[v] && a[u][v]) {
      DFS(v);
    }
  }
  return 1;
}

int check(int u, int v) {
  memset(vs, 0, sizeof(vs));
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!vs[i]) {
      cnt += DFS(i);
    }
  }
  return cnt;
}

void process() {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!vs[i]) {
      DFS(i);
      cnt++;
    }
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i][j]) {
        a[i][j] = a[j][i] = 0;
        if (cnt < check(i, j)) { ans.push_back({i, j}); }
        a[i][j] = a[j][i] = 1;
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto p : ans) {
    cout << p.first << ' ' << p.second << '\n';
  }
}

void nhap() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
}

int main() {
  freopen("TK.INP", "r", stdin);
  freopen("TK.OUT", "w", stdout);
  nhap();
  process();
  return 0;
}

