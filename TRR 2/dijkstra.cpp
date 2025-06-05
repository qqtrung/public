#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;
const int INF = 1e9;

int n, s, t;
int cost[MAX][MAX];
int dist[MAX], trace[MAX];
bool visited[MAX];

void dijkstra(int s) {
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
        visited[i] = false;
        trace[i] = -1;
    }

    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (int v = 1; v <= n; ++v) {
            // Bỏ qua cạnh không tồn tại (giá trị 10000 và u != v)
            if (!visited[v] && cost[u][v] != 10000 && dist[v] > dist[u] + cost[u][v]) {
                dist[v] = dist[u] + cost[u][v];
                trace[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

vector<int> get_path(int s, int t) {
    vector<int> path;
    if (dist[t] == INF) return path;
    for (int v = t; v != -1; v = trace[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    cin >> n >> s >> t;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> cost[i][j];

    dijkstra(s);

    if (dist[t] == INF) {
        cout << 0 << '\n';
    } else {
        cout << dist[t] << '\n';
        vector<int> path = get_path(s, t);
        for (int v : path) cout << v << ' ';
        cout << '\n';
    }

    return 0;
}
