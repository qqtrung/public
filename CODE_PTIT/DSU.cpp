#include <bits/stdc++.h>
using namespace std;

int sz[100005];
int parent[100005];
int t, n, m;

void Init() {
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    sz[i] = 1;
  }
}

int Find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
  int a = Find(u);
  int b = Find(v);
  if (a == b) return;
  if (sz[a] < sz[b]) {
    swap(a, b);
  }
  parent[b] = a;
  sz[a] += sz[b];
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    Init();
    int u, v;
    while (m--) {
      cin >> u >> v;
      if (Find(u) != Find(v))
        Union(u, v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (i == parent[i]) {
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
}
