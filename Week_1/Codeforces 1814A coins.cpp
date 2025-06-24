#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll t; cin >> t;

    for(int i=1; i<=t; i++){
        ll n; cin >> n;
        ll k; cin >> k;

        if(n%2==0) cout << "YES" << endl;
        else if(k%2==1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
