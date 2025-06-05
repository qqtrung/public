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

int check(int u) {
  memset(vs, 0, sizeof(vs));
  vs[u] = 1;
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
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (cnt < check(i)) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << '\n';
  if (ans.size() > 0) {
    for (int i : ans) {
      cout << i << ' ';
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
}

int main() {
  freopen("TK.INP", "r", stdin);
  freopen("TK.OUT", "w", stdout);
  nhap();
  process();
  return 0;
}

