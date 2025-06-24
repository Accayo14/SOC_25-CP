#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int lengths[N];
    for(int i=0; i<N; i++) cin >> lengths[i];

    sort(lengths, lengths + N);
    int median = lengths[N / 2];
    long long ans = 0;

    for (int i = 0; i < N; i++) {
        ans += abs(median - lengths[i]);
    }
    cout << ans;
}