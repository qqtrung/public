#include <bits/stdc++.h>
using namespace std;

int n, s;
set<int> adj[1000];
int vs[1000] = {};

vector<vector<int>> ans;
vector<int> cycle;

void nhap() {
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      if (x) {
        adj[i].insert(j);
      }
    }
  }
}

void dfs(int u) {
  vs[u] = 1;
  cycle.push_back(u);
  if (cycle.size() == n) {
    if (adj[cycle.back()].find(cycle.front()) != adj[cycle.back()].end()) {
      ans.push_back(cycle);
      ans.back().push_back(cycle.front());
    }
    return;
  }
  for (int v : adj[u]) {
    if (!vs[v]) {
      dfs(v);
      cycle.pop_back();
      vs[v] = 0;
    }
  }
}

void hamilton(int s) {
  dfs(s);
  if (ans.size()) {
    cout << ans.size() << '\n';
    for (auto v : ans) {
      for (auto i : v) {
        cout << i << ' ';
      }
      cout << '\n';
    }
  } else {
    cout << 0;
  }
}

int main() {
  // freopen("CT.INP", "r", stdin);
  // freopen("CT.OUT", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  nhap();
  hamilton(s);
  return 0;
}

