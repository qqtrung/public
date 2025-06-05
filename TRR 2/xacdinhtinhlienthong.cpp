#include <bits/stdc++.h>
using namespace std;

int n;
int a[110][110];
int vs[110];
vector<int> vt;

void DFS_DIR(int u) {
  vs[u] = 1;
  vt.push_back(u);
  for (int v = 1; v <= n; v++) {
    if (v != u && !vs[v] && a[u][v]) {
      DFS_DIR(v);
    }
  }
}

void DFS_NOT_DIR(int u) {
  vs[u] = 1;
  for (int v = 1; v <= n; v++) {
    if (v != u && !vs[v] && (a[u][v] || a[v][u])) {
      DFS_NOT_DIR(v);
    }
  }
}

void reset() {
  vt.clear();
  memset(vs, 0, sizeof(vs));
}

bool connect() {
  reset();
  DFS_NOT_DIR(1);
  for (int i = 1; i <= n; i++) {
    if (!vs[i]) {
      return false;
    }
  }
  return true;
}

bool strong() {
  for (int i = 1; i <= n; i++) {
    reset();
    DFS_DIR(i);
    if (vt.size() != n) {
      return false;
    }
  }
  return true;
}

void process() {
  if (strong()) {
    cout << 1;
  } else {
    if (connect()) {
      cout << 2;
    } else {
      cout << 0;
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
  nhap();
  process();
  return 0;
}



