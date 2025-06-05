#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;
const int INF = 1e9;

int n, s, t;
int cost[MAX][MAX];
int dist[MAX];
int trace[MAX];

struct Edge {
    int u, v, w;
};

vector<Edge> edges;

bool bellmanFord(int s) {
    fill(dist, dist + n + 1, INF);
    fill(trace, trace + n + 1, -1);
    dist[s] = 0;

    for (int i = 1; i < n; ++i) {
        for (const Edge& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                trace[e.v] = e.u;
            }
        }
    }

    for (const Edge& e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            return false;
        }
    }

    return true;
}

vector<int> getPath(int s, int t) {
    vector<int> path;
    if (dist[t] == INF) return path;
    for (int v = t; v != -1; v = trace[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    cin >> n >> s >> t;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> cost[i][j];
            if (i != j && cost[i][j] != 10000)
                edges.push_back({i, j, cost[i][j]});
        }

    if (bellmanFord(s)) {
        if (dist[t] == INF) {
            cout << 0 << '\n';
        } else {
            cout << dist[t] << '\n';
            vector<int> path = getPath(s, t);
            for (int v : path) cout << v << ' ';
            cout << '\n';
        }
    } else {
        cout << -1 << '\n';
    }


    return 0;
}
