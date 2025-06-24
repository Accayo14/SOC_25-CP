#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] = (parent[x] == x ? x : find(parent[x]));
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

ll solve(vector<int>& a, int n, ll p) {
    vector<pair<int, int>> vals;
    for (int i = 0; i < n; i++) 
        vals.emplace_back(a[i], i);
    sort(vals.begin(), vals.end());
    
    DSU dsu(n);
    ll ans = 0;
    vector<bool> visited(n, false); // Track processed nodes for expansion

    for (auto [val, idx] : vals) {
        if (val >= p) break;
        if (visited[idx]) continue;

        // Expand right
        int r = idx;
        int curr_gcd = val;
        while (r + 1 < n) {
            curr_gcd = gcd(curr_gcd, a[r+1]);
            if (curr_gcd != val) break;
            if (dsu.unite(r, r+1)) 
                ans += val;
            else 
                break;
            r++;
        }

        // Expand left
        int l = idx;
        curr_gcd = val;
        while (l - 1 >= 0) {
            curr_gcd = gcd(curr_gcd, a[l-1]);
            if (curr_gcd != val) break;
            if (dsu.unite(l-1, l)) 
                ans += val;
            else 
                break;
            l--;
        }
        visited[idx] = true;
    }

    // Connect remaining components with weight p
    for (int i = 0; i < n-1; i++) {
        if (dsu.unite(i, i+1)) 
            ans += p;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n; ll p;
        cin >> n >> p;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        cout << solve(a, n, p) << '\n';
    }
}
