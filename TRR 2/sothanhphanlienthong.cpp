#include <bits/stdc++.h>
using namespace std;

int n, x, res = 0;
vector<vector<int>> tplt;
vector<vector<int>> e;
vector<int> vs;

void dfs(int u) {
    vs[u] = 1;
    tplt[res].push_back(u);
    for (int i = 0; i < e[u].size(); ++i) {
        int v = e[u][i];
        if (vs[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
    cin >> n;
    e.resize(n + 1);
    vs.resize(n + 1, 0);
  	tplt.resize(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            if (x == 1) e[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (vs[i] == 0) {
            res++;
            dfs(i);
        }
    }
    cout << res << '\n';
    for (auto v : tplt) {
    	if (v.size()) {
    		sort(v.begin(), v.end());
	    	for (int i : v) {
	    		cout << i << ' ';
	    	}
	    	cout << '\n';
    	}
    }
    return 0;
}

