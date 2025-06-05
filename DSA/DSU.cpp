#include <bits/stdc++.h>
using namespace std;

int n, m;
int sz[100001];
int parent[100001];

void Init() {
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    sz[i] = 1;
  }
}

int Find(int u) {
  if (u == parent[u])
    return u;
  return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
  int ru = Find(u);
  int rv = Find(v);
  if (ru == rv)
    return false;
  if (sz[ru] < sz[rv])
    swap(ru, rv);
  parent[rv] = ru;
  sz[ru] += sz[rv];
  return true;
}

void solve() {
  cin >> n >> m;
  Init();
  vector<pair<int, int>> c;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    c.push_back({x, y});
  }
  for (auto x : c) {
    if (!Union(x.first, x.second)) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
