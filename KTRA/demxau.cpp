#include <bits/stdc++.h>
using namespace std;

const int MAX_C = 61;
const int MAX_P = 21;
long long C[MAX_C][MAX_C];
long long P[MAX_P];

void BC() {
  for (int n = 0; n < MAX_C; ++n) {
    C[n][0] = 1;
    for (int k = 1; k <= n; ++k) {
      C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }
  }
}

void BP(){
  P[0] = 1;
  for(int i = 1; i < MAX_P; i++) {
    P[i] = P[i-1] * i;
  }
}

void get_kth_string(int a, int b, long long k) {
  string result;
  while (a > 0 || b > 0) {
    if (a == 0) {
      result += 'b';
      --b;
    } else if (b == 0) {
      result += 'a';
      --a;
    } else {
      long long count_with_a_first = C[a - 1 + b][a - 1];
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
  cout << result << endl;
}

void get_kth_combination(int n, int k, long long kth) {
  vector<int> ans(k + 1, 0);
  for (int i = 1; i <= k; i++) {
    int val = ans[i - 1] + 1;
    while (1) {
      long long count_with_val_first = C[n - val][k - i];
      if (count_with_val_first >= kth) break;
      kth -= count_with_val_first;
      val++;
    }
    ans[i] = val;
  }
  for (int i = 1; i <= k; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}

void get_kth_permutation(int n, long long kth) {
  vector<int> ans(n + 1, 0);
  vector<int> visited(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int val = 1;
    while (1) {
      if (visited[val]) {
        val++;
        continue;
      }
      long long count_with_val_first = P[n - i];
      if (count_with_val_first >= kth) break;
      kth -= count_with_val_first;
      val++;
    }
    ans[i] = val;
    visited[val] = 1;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}

void get_combination_kth(int n, int k, vector<int> a) {
  a.insert(a.begin(), 0);

  long long cnt = 0;
  for (int i = 1; i <= k; i++) {
    int val = a[i];
    for (int j = a[i - 1] + 1; j < val; j++) {
      long long count_with_j_first = C[n - j][k - i];
      cnt += count_with_j_first;
    }
  }
  cout << cnt + 1 << endl;
}

int main() {

  BC();
  BP();

  for (int i = 1; i <= 10; i++) {
    cout << i << ": ";
    get_kth_string(4, 5, i);
  }

  for (int i = 1; i <= C[5][3]; i++) {
    cout << i << ": ";
    get_kth_combination(5, 3, i);
  }

  for (int i = 1; i <= P[5]; i++) {
    cout << i << ": ";
    get_kth_permutation(5, i);
  }

  get_combination_kth(5, 3, {1, 2, 3});

  return 0;
}
