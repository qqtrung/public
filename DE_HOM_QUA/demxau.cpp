#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 61;
ll C[MAX][MAX];

void build_combinations() {
  for (int n = 0; n < MAX; ++n) {
    C[n][0] = 1;
    for (int k = 1; k <= n; ++k) {
      C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }
  }
}

string get_kth_string(int a, int b, ll k) {
  string result;
  while (a > 0 || b > 0) {
    if (a == 0) {
      result += 'b';
      --b;
    } else if (b == 0) {
      result += 'a';
      --a;
    } else {
      ll count_with_a_first = C[a + b - 1][a - 1];
      if (k <= count_with_a_first) {
        result += 'a';
        --a;
      } else {
        result += 'b';
        k -= count_with_a_first;
        --b;
      }
    }
  }
  return result;
}

int main() { return 0; }
