#include <bits/stdc++.h>
using namespace std;

int n, s, e;
vector<vector<int>> g;
vector<int> vs;
vector<int> par;

void bfs() {
    vs.assign(n + 1, 0);
    par.assign(n + 1, -1);

    queue<int> q;
    q.push(s);
    vs[s] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (!vs[v]) {
                vs[v] = 1;
                par[v] = u;
                q.push(v);
            }
        }
    }

    if (!vs[e]) {
        cout << "No path from " << s << " to " << e << "\n";
        return;
    }

    cout << "BFS path: ";
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
    bfs();
    return 0;
}
