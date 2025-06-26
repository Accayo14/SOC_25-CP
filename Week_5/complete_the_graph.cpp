#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const ll INF = 1e18;

struct Edge {
    int u, v;
    ll w;
    int id;
};

int n, m, s, t;
ll L;
vector<Edge> edges;
vector<vector<pair<int, ll>>> adj;
vector<ll> dist;

ll dijkstra(int start, int target) {
    dist.assign(n, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist[target];
}

void buildGraph() {
    adj.assign(n, vector<pair<int, ll>>());
    
    for (const Edge& e : edges) {
        if (e.w > 0) {
            adj[e.u].push_back({e.v, e.w});
            adj[e.v].push_back({e.u, e.w});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> L >> s >> t;
    
    edges.resize(m);
    vector<int> zeroEdges;
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].id = i;
        
        if (edges[i].w == 0) {
            zeroEdges.push_back(i);
        }
    }
    
    // Build initial graph without zero-weight edges
    buildGraph();
    
    // Check if shortest path without zero edges is already too small
    ll initialDist = dijkstra(s, t);
    if (initialDist < L) {
        cout << "NO\n";
        return 0;
    }
    
    // If already equals L, set zero edges to large values
    if (initialDist == L) {
        cout << "YES\n";
        for (const Edge& e : edges) {
            if (e.w == 0) {
                cout << e.u << " " << e.v << " " << INF << "\n";
            } else {
                cout << e.u << " " << e.v << " " << e.w << "\n";
            }
        }
        return 0;
    }
    
    // Set all zero edges to weight 1 initially
    for (int idx : zeroEdges) {
        edges[idx].w = 1;
    }
    
    // Rebuild graph with all edges having weight >= 1
    buildGraph();
    
    // Try to adjust one zero edge at a time
    for (int i = 0; i < zeroEdges.size(); i++) {
        int edgeIdx = zeroEdges[i];
        
        // Temporarily set this edge to weight 1 and calculate shortest path
        edges[edgeIdx].w = 1;
        buildGraph();
        
        ll currentDist = dijkstra(s, t);
        
        if (currentDist <= L) {
            // This edge can be used to achieve target distance
            ll needed = L - currentDist + 1;
            edges[edgeIdx].w = needed;
            
            // Set remaining zero edges to large values
            for (int j = i + 1; j < zeroEdges.size(); j++) {
                edges[zeroEdges[j]].w = INF;
            }
            
            cout << "YES\n";
            for (const Edge& e : edges) {
                cout << e.u << " " << e.v << " " << e.w << "\n";
            }
            return 0;
        }
    }
    
    cout << "NO\n";
    return 0;
}
