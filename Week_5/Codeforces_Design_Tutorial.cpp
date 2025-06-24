#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<ll>> d(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    // Initial checks
    for (int i = 0; i < n; i++) {
        if (d[i][i] != 0) {
            cout << "NO" << endl;
            return 0;
        }
        for (int j = i + 1; j < n; j++) {
            if (d[i][j] != d[j][i] || d[i][j] <= 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    if (n == 1) {
        cout << "YES" << endl;
        return 0;
    }

    // Use node 0 as root
    vector<ll> base = d[0];
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) nodes[i] = i;

    sort(nodes.begin(), nodes.end(), [&](int a, int b) {
        return base[a] < base[b];
    });

    if (base[nodes[0]] != 0 || nodes[0] != 0) {
        cout << "NO" << endl;
        return 0;
    }

    // Build tree
    vector<vector<pair<int, ll>>> adj(n);
    vector<bool> processed(n, false);
    processed[0] = true;

    for (int idx = 1; idx < n; idx++) {
        int i = nodes[idx];
        int candidate = -1;
        ll best_base = -1;

        for (int j_idx = 0; j_idx < idx; j_idx++) {
            int j = nodes[j_idx];
            if (base[j] >= base[i]) continue;
            if (base[j] + d[j][i] == base[i]) {
                if (candidate == -1 || base[j] > best_base) {
                    candidate = j;
                    best_base = base[j];
                }
            }
        }

        if (candidate == -1) {
            cout << "NO" << endl;
            return 0;
        }

        ll w = base[i] - base[candidate];
        adj[i].push_back({candidate, w});
        adj[candidate].push_back({i, w});
        processed[i] = true;
    }

    // Optimized BFS verification: use a single distance vector and reset
    vector<ll> dist(n);
    for (int i = 0; i < n; i++) {
        fill(dist.begin(), dist.end(), -1);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto [v, w] : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + w;
                    q.push(v);
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (dist[j] != d[i][j]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}
