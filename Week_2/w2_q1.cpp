#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> songs(n);
    set<ll> seen;
    ll maxlen = 0;
    ll l = 0;

    for (ll r = 0; r < n; r++) {
        cin >> songs[r];
        while (seen.count(songs[r])) {
            seen.erase(songs[l]);
            l++;
        }
        seen.insert(songs[r]);
        maxlen = max(maxlen, r - l + 1);
    }

    cout << maxlen << endl;
    return 0;
}
