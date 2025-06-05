#include <bits/stdc++.h>
using namespace std;

int n;
set<int> adj[110];
int vs[110] = {};
int din[110] = {};
int dout[110] = {};

void DFS(int u) {
  vs[u] = 1;
  for (int v : adj[u]) {
    if (!vs[v]) {
      DFS(v);
    }
  }
}

bool connect() {
  DFS(1);
  for (int i = 1; i <= n; i++) {
    if (!vs[i]) {
      return false;
    }
  }
  return true;
}

void solve1() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      if (x) {
        dout[i]++;
        din[j]++;
        adj[i].insert(j);
        adj[j].insert(i);
      }
    }
  }

  if (!connect()) {
    cout << 0;
    return;
  }

  int x = 0, y = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (dout[i] - din[i] ==  0) cnt++;
    if (dout[i] - din[i] ==  1) x++;
    if (dout[i] - din[i] == -1) y++;
  }
  if (cnt == n) {
    cout << 1;
  } else {
    if (x == 1 && y == 1) {
      cout << 2;
    } else {
      cout << 0;
    }
  }
}

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
      //adj[y].erase(x);
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

void solve2() {
  int u;
  cin >> n >> u;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      if (x) {
        adj[i].insert(j);
      }
    }
  }
  euler(u);
}


int main() {
  // freopen("DT.INP", "r", stdin);
  // freopen("DT.OUT", "w", stdout);
  freopen("CT.INP", "r", stdin);
  freopen("CT.OUT", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  if (t == 1) {
    solve1();
  } else {
    solve2();
  }
  return  0;
}