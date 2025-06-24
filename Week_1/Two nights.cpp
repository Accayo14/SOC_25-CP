#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    for(ll k=1; k<=n; k++){
        ll possibleways = k*k*((k*k)-1)/2;
        ll attackingways = 4*(k-1)*(k-2);
        ll ans = possibleways - attackingways;

        cout << ans << "\n";
    }
}
