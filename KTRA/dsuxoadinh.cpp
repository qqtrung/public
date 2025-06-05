#include <bits/stdc++.h>
using namespace std;

int n, m;
int sz[100001];
int parent[100001];
int num_comp = 0;

vector<int> query;
vector<int> del;
vector<vector<int>> adj;

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

bool Union(int u, int v) {
  int ru = Find(u);
  int rv = Find(v);
  if (ru == rv) {
    return false;
  }
  if (sz[ru] < sz[rv]) swap(ru, rv);
  parent[rv] = ru;
  sz[ru] += sz[rv];
  return true;
}

void solve() {
  cin >> n >> m;
  adj.clear();
  adj.resize(n + 1, vector<int>());
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  query.clear();
  query.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> query[i];
  }

  del.clear();
  del.resize(n + 1, 1);

  Init();

  vector<string> ans;

  for (int i = n; i >= 1; i--) {
    int u = query[i];
    del[u] = 0;
    num_comp++;

    for (int v : adj[u]) {
      if (!del[v]) {
        if(Union(u, v)){
          num_comp--;
        }
      }
    }

    if (num_comp == 1) {
      ans.push_back("YES");
    } else ans.push_back("NO");
  }

  reverse(ans.begin(), ans.end());
  for (auto c : ans) {
    cout << c << endl;
  }

}

int main() {
    solve();
    return 0;
}
