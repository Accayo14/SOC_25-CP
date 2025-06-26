#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> graph(n+1);
    vector<long long> dist(n+1, INF);
    vector<int> prev(n+1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;

        for (auto [v, weight] : graph[u]) {
            long long new_dist = dist[u] + weight;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1 << endl;
    } else {
        vector<int> path;
        int cur = n;
        while (cur != -1) {
            path.push_back(cur);
            cur = prev[cur];
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++) {
            if (i > 0) cout << " ";
            cout << path[i];
        }
        cout << endl;
    }

    return 0;
}
