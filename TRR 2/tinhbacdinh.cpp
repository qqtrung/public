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
    int deg = 0;
    for (int j = 1; j <= n; j++) {
      deg += a[i][j];
    }
    cout << deg << ' ';
  }
}

void solve2() {
  vector<pair<int, int>> ans;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (i < j && a[i][j]) {
        ans.push_back({i, j});
      }
    }
  }
  cout << n << ' ' << ans.size() << '\n';
  for (auto p : ans) {
    cout << p.first << ' ' << p.second << '\n';
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

