#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    ll t; cin >> t;
    vector<ll> time(n);
    ll minimum = LLONG_MAX;
    for(int i=0; i<n; i++) {
        cin >> time[i];
        minimum = min(minimum, time[i]);
    }

    ll left = 1;
    ll right = t*minimum;
    ll answer = right;

    while(right>=left){
        ll mid = (left + right)/2;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (mid / time[i]);
            if(sum>=t) break;
        }
        
        if(sum<t){
            left = mid+1;
        }
        else if(sum>=t){
            answer = mid;
            right = mid-1;
        }
    }

    cout << answer;
}