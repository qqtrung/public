#include <bits/stdc++.h>
using namespace std;

void OutVector(vector<int> &a) {
  for (int i : a) {
    cout << i << ' ';
  }
  cout << '\n';
}

void Selection_sort(vector<int> a, int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[min_idx]) {
        min_idx = j;
      }
    }
    swap(a[i], a[min_idx]);
  }
  OutVector(a);
}

void Insertion_sort(vector<int> a, int n) {
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = key;
  }
  OutVector(a);
}

void Bubble_sort(vector<int> a, int n) {
  for (int i = 0; i < n; i++) {
    bool check = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        check = true;
        swap(a[j], a[j + 1]);
      }
    }
    if (!check)
      break;
  }
  OutVector(a);
}

long long merge(vector<int> &a, int l, int m, int r) {
  vector<int> left(a.begin() + l, a.begin() + m + 1);
  vector<int> right(a.begin() + m + 1, a.begin() + r + 1);
  int i = 0, j = 0, k = l;
  long long inv_count = 0;
  while (i < left.size() && j < right.size()) {
    if (left[i] <= right[j]) {
      a[k++] = left[i++];
    } else {
      a[k++] = right[j++];
      inv_count += left.size() - i;
    }
  }
  while (i < left.size())
    a[k++] = left[i++];
  while (j < right.size())
    a[k++] = right[j++];
  return inv_count;
}

long long Merge_sort(vector<int> &a, int l, int r) {
  if (l >= r)
    return 0;
  int m = l + (r - l) / 2;
  long long cnt = 0;
  cnt += Merge_sort(a, l, m);
  cnt += Merge_sort(a, m + 1, r);
  cnt += merge(a, l, m, r);
  return cnt;
}

int main() {

  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  Selection_sort(a, n);
  Insertion_sort(a, n);
  Bubble_sort(a, n);

  cout << Merge_sort(a, 0, n - 1) << '\n';
  OutVector(a);

  cout << lower_bound(a.begin(), a.end(), 3) - a.begin() << '\n';
  cout << upper_bound(a.begin(), a.end(), 3) - a.begin() << '\n';

  return 0;
}
