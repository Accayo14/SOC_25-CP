#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    vector<string> solution(n, string(m, ' '));
    
    // Use a checkerboard pattern with two sets of colors
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char original_char = grid[i][j];
            int parity = (i + j) % 2;
            
            if (parity == 0) {  // Even cells get C or D
                solution[i][j] = (original_char != 'C') ? 'C' : 'D';
            } else {  // Odd cells get A or B
                solution[i][j] = (original_char != 'A') ? 'A' : 'B';
            }
        }
    }
    
    // Print the solution
    for (int i = 0; i < n; i++) {
        cout << solution[i] << endl;
    }
    
    return 0;
}
