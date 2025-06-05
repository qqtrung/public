#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w, idx; // thêm chỉ số để giữ thứ tự nhập
    bool operator < (const Edge &other) const {
        if (w != other.w) return w < other.w;
        return idx < other.idx; // đảm bảo ổn định
    }
};

int n, m;
vector<Edge> edges;
int parent[105], rank_[105];

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return false;
    if (rank_[a] < rank_[b]) swap(a, b);
    parent[b] = a;
    if (rank_[a] == rank_[b]) rank_[a]++;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].idx = i; // lưu thứ tự gốc
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank_[i] = 0;
    }

    sort(edges.begin(), edges.end()); // so sánh ổn định

    vector<Edge> mst;
    int total_weight = 0;

    for (auto &e : edges) {
        if (union_set(e.u, e.v)) {
            mst.push_back(e);
            total_weight += e.w;
            if ((int)mst.size() == n - 1) break;
        }
    }

    if ((int)mst.size() != n - 1) {
        cout << 0 << "\n";
    } else {
        cout << total_weight << "\n";
        for (auto &e : mst) {
            cout << e.u << " " << e.v << " " << e.w << "\n";
        }
    }

    return 0;
}
