#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin >> t;

    for(ll i=0; i<t; i++){
        ll x1; cin >> x1;
        ll y1; cin >> y1;
        ll x2; cin >> x2;
        ll y2; cin >> y2;
        ll count = 0;

        if(y2<y1){
            cout << -1 << endl;
            continue;
        }

        count += (y2-y1);
        x1 += count;

        if(x2>x1){
            cout << -1 << endl;
            continue;
        }

        count += (x1-x2);
        cout << count << endl;
    }
}
