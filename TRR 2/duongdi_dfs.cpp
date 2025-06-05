#include <bits/stdc++.h>
using namespace std;

int n, s, e;
vector<vector<int>> g;
vector<int> vs;
vector<int> par;

void dfsStack() {
    vs.assign(n + 1, 0);
    par.assign(n + 1, -1);
    stack<int> st;
    st.push(s);
    vs[s] = 1;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : g[u]) {
            if (!vs[v]) {
                vs[v] = 1;
                par[v] = u;
                st.push(u);
                st.push(v);
                break;
            }
        }
    }
    if (!vs[e]) {
        cout << "No path from " << s << " to " << e << "\n";
        return;
    }
    cout << "DFS path (stack): ";
    vector<int> path;
    for (int v = e; v != -1; v = par[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (int v : path) {
        cout << v << " ";
    }
    cout << "\n";
}

bool dfsRecursive(int u) {
    vs[u] = 1;
    if (u == e) return true;
    for (int v : g[u]) {
        if (!vs[v]) {
            par[v] = u;
            if (dfsRecursive(v)) return true;
        }
    }
    return false;
}

void dfsDequy() {
    vs.assign(n + 1, 0);
    par.assign(n + 1, -1);

    bool found = dfsRecursive(s);

    if (!found) {
        cout << "No path from " << s << " to " << e << "\n";
        return;
    }

    cout << "DFS path (recursive): ";
    vector<int> path;
    for (int v = e; v != -1; v = par[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (int v : path) {
        cout << v << " ";
    }
    cout << "\n";
}

void nhap() {
    cin >> n >> s >> e;
    g.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            if (x == 1) {
                g[i].push_back(j);
            }
        }
    }
}

int main() {
    nhap();
    dfsStack();
    // dfsDequy();
    return 0;
}
