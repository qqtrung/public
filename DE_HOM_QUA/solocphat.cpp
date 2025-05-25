#include <bits/stdc++.h>
using namespace std;

void lietKeSoLocPhat(int N) {
  queue<string> q;
  q.push("6");
  q.push("8");
  int count = 0;
  while (count < N) {
    string s = q.front();
    q.pop();
    string b = s;
    reverse(b.begin(), b.end());
    cout << s << b << ' ';
    count++;
    q.push(s + "6");
    q.push(s + "8");
  }
}

void solve() {}

int main() { return 0; }
