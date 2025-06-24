#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    for(int j=0;j<t;j++){
        int l; cin >> l;
        int r; cin >> r;

        int maxdif = -1;
        int max = -1;

        for(int i=l; i<=r; i++){
            string num = to_string(i);
            sort(num.begin(), num.end());
            int dif = num[num.length() - 1] - num[0];
            if(dif>maxdif){
                maxdif = dif;
                max = i;
            }
            if(maxdif == 9){
                break;
            }
        }

        cout << max << endl;
    }
}
