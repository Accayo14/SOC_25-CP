#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<ll> numbers;
    ll x; cin >> x;
    numbers.push_back(x);
    ll count = 0;

    for(ll i=1; i<n; i++){
        cin >> x;

        if(x>=numbers[i-1]){
            numbers.push_back(x);
        }
        else{
            count += -(x - numbers[i-1]);
            numbers.push_back(numbers[i-1]);
        }
    }
    cout << count;
}