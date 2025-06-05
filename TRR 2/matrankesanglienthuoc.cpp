#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int n;
int din[1000] = {};
int dout[1000] = {};
int a[110][10010] = {};

void solve1() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      if (x == 1) {
        dout[i]++;
        din[j]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << din[i] << ' ' << dout[i] << '\n';
  }
}

void solve2() {
  cin >> n;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      if (x == 1) {
        cnt++;
        a[i][cnt] = 1;
        a[j][cnt] = -1;
      }
    }
  }
  cout << n << ' ' << cnt << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= cnt; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main() {
  freopen("DT.INP", "r", stdin);
  freopen("DT.OUT", "w", stdout);
  int t;
  cin >> t;
  if (t == 1) {
    solve1();
  } else {
    solve2();
  }
  return 0;
}
