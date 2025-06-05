#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> adj[1000];
int a[110][110];
int vs[110] = {};
int deg[1000] = {};

void euler(int v) {
  stack<int> st;
  vector<int> EC;
  st.push(v);
  while (!st.empty()) {
    int x = st.top();
    if (adj[x].size() != 0) {
      int y = *adj[x].begin();
      st.push(y);
      adj[x].erase(y);
      adj[y].erase(x);//xóa nếu có hướng
    } else {
      st.pop();
      EC.push_back(x);
    }
  }
  reverse(begin(EC), end(EC));
  for (int x : EC) {
    cout << x << " ";
  }
}

void solve1() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j]) {
        deg[i]++;
      }
    }
  }
  {
    queue<int> q;
    q.push(1);
    vs[1] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v = 1; v <= n; v++) {
        if (v != u && !vs[v] && a[u][v]) {
          vs[v] = 1;
          q.push(v);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!vs[i]) {
        cout << 0;
        return;
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (deg[i] % 2 == 1) {
      cnt++;
    }
  }
  if (cnt == 0) {
    cout << 1;
  } else if (cnt == 2) {
    cout << 2;
  } else {
    cout << 0;
  }
}

void solve2() {
  int u;
  cin >> n >> u;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j]) {
        adj[i].insert(j);
      }
    }
  }
  euler(u);
}

int main() {
  // freopen("CT.INP", "r", stdin);
  // freopen("CT.OUT", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  if (t == 1) solve1();
  else solve2();
  return 0;
}

