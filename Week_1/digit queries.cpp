#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int q;
    cin >> q;
    vector<ll> queries(q);
    for (int i = 0; i < q; ++i) cin >> queries[i];

    for(ll N : queries){
        ll digits = 1, base = 9;

        while(N - digits*base > 0){
            N -= digits*base;
            base *= 10;
            digits++;
        }
        ll index = N % digits;

        ll res = (ll)pow(10, digits-1) + (N-1)/digits;

        if (index != 0)
            res = res / (ll)pow(10, digits - index);
        cout << res % 10 << "\n";

    }
}