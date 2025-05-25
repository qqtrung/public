#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int sz[100001];
int parent[100001];
map<int, int> delEdge;
vector<pair<int, int>> edge;
vector<pair<int, int>> query;

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
    cin >> n >> m >> q;
    edge.resize(1);
    query.resize(1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        edge.push_back({x, y});
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        query.push_back({x, y});
        delEdge[x]++;
    }
    Init();
    for (int i = 1; i <= m; i++) {
        if (!delEdge[i]) {
            Union(edge[i].first, edge[i].second);
        }
    }
    vector<int> ans(q + 1);
    for (int k = q; k >= 1; k--) {
        ans[k] = sz[Find(query[k].second)];
        delEdge[query[k].first]--;
        if (delEdge[query[k].first] <= 0) {
            Union(edge[query[k].first].first, edge[query[k].first].second);
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    solve();
    return 0;
}
