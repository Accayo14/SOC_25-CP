#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> coins(N);
    for (int i = 0; i < N; ++i)
        cin >> coins[i];
    
    vector<ll> dp(X + 1, 0);

    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = coins[i]; j <= X; j++) {
            dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
        }
    }

    cout << dp[X];
    return 0;
}
