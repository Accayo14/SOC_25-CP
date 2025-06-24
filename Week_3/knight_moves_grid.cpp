#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Direction arrays for knight moves
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
    
    // Distance array to store minimum moves
    vector<vector<int>> dist(n, vector<int>(n, -1));
    
    // BFS queue
    queue<pair<int, int>> q;
    
    // Start BFS from target position (0, 0)
    q.push({0, 0});
    dist[0][0] = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        // Try all 8 possible knight moves
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // Check if the new position is within bounds
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                // If not visited yet
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    // Output the result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
