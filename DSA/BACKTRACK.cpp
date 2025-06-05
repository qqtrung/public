#include <bits/stdc++.h>
using namespace std;

void binary(int depth, int n, vector<int> &a, vector<char> &val) {
  if (depth == n + 1) {
    for (int i = 1; i <= n; i++) {
      cout << a[i] << ":" << val[a[i]] << " ";
    }
    cout << '\n';
    return;
  }
  for (int i = 0; i <= 1; i++) {
    a[depth] = i;
    binary(depth + 1, n, a, val);
  }
}

void combination(int depth, int n, int k, vector<int> &a, vector<char> &val) {
  if (depth == k + 1) {
    for (int i = 1; i <= k; i++) {
      cout << a[i] << ":" << val[a[i]] << " ";
    }
    cout << '\n';
    return;
  }
  for (int i = a[depth - 1] + 1; i <= n - k + depth; i++) {
    a[depth] = i;
    combination(depth + 1, n, k, a, val);
  }
}
                                                                            
void permutation(int depth, int n, vector<int> &a, vector<char> &val,
                 vector<int> &visited) {
  if (depth == n + 1) {
    for (int i = 1; i <= n; i++) {
      cout << a[i] << ":" << val[a[i]] << " ";
    }
    cout << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      visited[i] = 1;
      a[depth] = i;
      permutation(depth + 1, n, a, val, visited);
      visited[i] = 0;
    }
  }
}

void xephau(int depth, int n, vector<vector<int>> &a, vector<int> &x,
            vector<int> &y, vector<int> &z) {
  if (depth == n + 1) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cout << a[i][j] << ' ';
      }
      cout << '\n';
    }
    cout << '\n';
    return;
  }
  for (int j = 1; j <= n; j++) {
    if (!z[j] && !x[depth + j] && !y[depth - j + n]) {
      a[depth][j] = 1;
      x[depth + j] = 1;
      y[depth - j + n] = 1;
      z[j] = 1;
      xephau(depth + 1, n, a, x, y, z);
      a[depth][j] = 0;
      x[depth + j] = 0;
      y[depth - j + n] = 0;
      z[j] = 0;
    }
  }
}

void out(vector<int> &a) {
  for (int i : a) {
    cout << i << ' ';
  }
  cout << '\n';
}

void tapcon(int n, vector<int> &a) {
  int x = a.back();
  for (int i = x + 1; i <= n; i++) {
    a.push_back(i);
    out(a);
    tapcon(n, a);
    a.pop_back();
  }
}

void phantich(int sum, int n, vector<int> &a) {
  if (sum == n) {
    out(a);
    return;
  }
  int x = a.back();
  for (int i = x; i <= n - sum; i++) {
    a.push_back(i);
    phantich(sum + i, n, a);
    a.pop_back();
  }
}

void sinh(int n) {
  vector<int> ans(n, 0);
  bool stop = false;
  while (!stop) {
    out(ans);
    int idx = n - 1;
    while (idx >= 0 && ans[idx]) {
      ans[idx] = 0;
      idx--;
    }
    if (idx < 0) stop = true;
    else {
      ans[idx] = 1;
    }
  }
}

void tohop(int n, int k) {
  vector<int> ans(k + 1);
  for (int i = 1; i <= k; i++) ans[i] = i;
  bool stop = false;
  while (!stop) {
    for (int i = 1; i <= k; i++) cout << ans[i] << ' '; cout << endl;
    int idx = k;
    while (idx >= 1 && ans[idx] == n - k + idx) {
      idx--;
    }
    if (idx < 1) stop = true;
    else {
      ans[idx]++;
      for (int i = idx + 1; i <= k; i++) ans[i] = ans[i-1] + 1;
    }
  }
}

bool next(vector<int>& ans, int n) {
  for (int i = n - 1; i >= 1; i--) {
    if (ans[i] < ans[i + 1]) {
      for (int j = n; j > i; j--) {
        if (ans[j] > ans[i]) {
          swap(ans[i], ans[j]);
          reverse(ans.begin() + i + 1, ans.end());
          return true;
        }
      }
    }
  }
  return false;
}

void hoanvi(int n) {
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) ans[i] = i;
  bool stop = false;
  while (!stop) {
    for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << endl;
    if (!next(ans, n)) stop = true;
  }
}

int main() {

  {
    cout << "binary: \n";
    int n = 2;
    vector<int> a;
    a.resize(n + 1);
    vector<char> val = {'a', 'b'};
    for (int i = 0; i <= 1; i++) {
      a[1] = i;
      binary(2, n, a, val);
    }
  }

  {
    cout << "combination: \n";
    int n = 3, k = 2;
    vector<int> a;
    a.resize(k + 1);
    vector<char> val = {'$', 'a', 'b', 'c', 'd'};
    for (int i = 1; i <= n - k + 1; i++) {
      a[1] = i;
      combination(2, n, k, a, val);
    }
  }

  {
    cout << "permutation: \n";
    int n = 3;
    vector<int> a;
    a.resize(n + 1);
    vector<char> val = {'$', 'a', 'b', 'c', 'd'};
    vector<int> visited;
    visited.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        visited[i] = 1;
        a[1] = i;
        permutation(2, n, a, val, visited);
        visited[i] = 0;
      }
    }
  }

  {
    cout << "xephau: \n";
    int n = 4;
    vector<int> x(100, 0);
    vector<int> y(100, 0);
    vector<int> z(100, 0);
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    for (int j = 1; j <= n; j++) {
      if (!z[j] && !x[1 + j] && !y[1 - j + n]) {
        a[1][j] = 1;
        x[1 + j] = 1;
        y[1 - j + n] = 1;
        z[j] = 1;
        xephau(2, n, a, x, y, z);
        a[1][j] = 0;
        x[1 + j] = 0;
        y[1 - j + n] = 0;
        z[j] = 0;
      }
    }
  }

  {
    cout << "tapcon: \n";
    int n = 5;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
      a.push_back(i);
      out(a);
      tapcon(n, a);
      a.pop_back();
    }
  }

  {
    cout << "phantich: \n";
    int n = 5;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
      a.push_back(i);
      phantich(i, n, a);
      a.pop_back();
    }
  }

  {
    cout << "binary: \n";
    sinh(3);
  }

  {
    cout << "combination: \n";
    tohop(5, 3);
  }

  {
    cout << "permutation: \n";
    hoanvi(5);
  }

  return 0;
}
