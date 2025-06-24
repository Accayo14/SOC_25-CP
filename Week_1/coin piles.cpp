#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll A, ll B){
    if ((2 * A - B) % 3 || (2 * A - B) < 0 || (2 * B - A) % 3 || (2 * B - A) < 0)
        return 0;
    return 1;
}

int main(){
    ll n;
    cin >> n;

    for(int i=0; i<n; i++){
        ll left;
        cin >> left;
        ll right;
        cin >> right;
        
        if(check(left,right)) cout << "YES \n";
        else cout << "NO \n";
    }
}