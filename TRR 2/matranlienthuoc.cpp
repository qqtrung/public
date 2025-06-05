#include <bits/stdc++.h>
using namespace std;

int n;
int a[110][110];

void solve1() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << accumulate(&a[i][1], &a[i][n + 1], 0) << ' ';
  }
}

void solve2() {
  vector<pair<int, int>> c;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j] && i < j) {
        c.push_back({i, j});
      }
    }
  }
  vector<vector<int>> ans(n + 1, vector<int>(c.size() + 1));
  cout << n << ' ' << c.size() << '\n';
  for (int i = 0; i < c.size(); i++) {
    ans[c[i].first][i + 1] = 1;
    ans[c[i].second][i + 1] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= c.size(); j++) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main() {
  // freopen("DT.INP", "r", stdin);
  // freopen("DT.OUT", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  if (t == 1) {
    solve1();
  } else {
    solve2();
  }
  return 0;
}
