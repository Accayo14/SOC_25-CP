#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n; cin >> n;
    ll x; cin >> x;
    vector <int> weights;

    for(int i=0; i<n; i++){
        ll wt; cin >> wt;
        weights.push_back(wt);
    }

    sort(weights.begin(),weights.end());
    int count = 0;
    int left = 0;
    int right = n-1;

    while(left <= right){
        if(weights[left] + weights[right] <= x){
            count++;
            left++;
            right--;
        }
        else{
            count++;
            right--;
        }
    }
    cout << count;
}
