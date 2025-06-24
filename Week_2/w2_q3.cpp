#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    int sum; cin >> sum;
    vector<pair<int, int>> numbers(n); // store value and original index
    for(int i=0; i<n; i++) {
        cin >> numbers[i].first;
        numbers[i].second = i+1; // 1-based index
    }

    sort(numbers.begin(), numbers.end());

    for(int i=0; i<n-2; i++) {
        int l=i+1, r=n-1;
        while(l < r){
            int curr_sum = numbers[l].first + numbers[r].first + numbers[i].first;
            if(curr_sum == sum){
                cout << numbers[i].second << " " << numbers[l].second <<" " << numbers[r].second << endl;
                return 0;
            }
            else if(curr_sum > sum){
                r--;
            }
            else{
                l++;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}