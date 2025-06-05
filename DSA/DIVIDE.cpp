#include <bits/stdc++.h>
using namespace std;

int md = 1e9 + 7;
vector<vector<int>> I;

int add(long long a, long long b) { return ((a % md) + (b % md)) % md; }
int mul(long long a, long long b) { return ((a % md) * (b % md)) % md; }

vector<vector<int>> mulMatrix(vector<vector<int>> a, vector<vector<int>> b) {
  int n = (int)a.size();
  int m = (int)b[0].size();
  vector<vector<int>> res(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < (int)b.size(); k++)
        res[i][j] = add(res[i][j], mul(a[i][k], b[k][j]));
  return res;
}

vector<vector<int>> power(vector<vector<int>> a, int t) {
  if (t == 0)
    return I;
  if (t == 1)
    return mulMatrix(a, I);
  auto x = power(a, t / 2);
  auto y = power(a, t % 2);
  return mulMatrix(x, mulMatrix(x, y));
}

int main() {
  vector<vector<int>> m = {{1, 1}, {1, 0}};
  I.resize(2, vector<int>(2, 0));
  for (int i = 0; i < 2; i++)
    I[i][i] = 1;
  auto res = power(m, 16);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cout << res[i][j] << ' ';
    }
    cout << '\n';
  }
}
