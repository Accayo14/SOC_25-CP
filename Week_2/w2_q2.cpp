#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int sum; cin >> sum;
    vector<pair<int, int>> numbers(n); // store value and original index
    for(int i=0; i<n; i++) {
        cin >> numbers[i].first;
        numbers[i].second = i+1; // 1-based index
    }

    sort(numbers.begin(), numbers.end());

    int l=0, r=n-1;
    while(l < r){
        int curr_sum = numbers[l].first + numbers[r].first;
        if(curr_sum == sum){
            cout << numbers[l].second << " " << numbers[r].second << endl;
            return 0;
        }
        else if(curr_sum > sum){
            r--;
        }
        else{
            l++;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
