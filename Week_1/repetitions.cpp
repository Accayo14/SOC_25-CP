#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    string s;
    cin >> s;
    char left = s[0];
    char right;
    int count = 0;
    int maxlen = 0;

    for(int i = 1; i<s.length(); i++){
        right = s[i];
        if(left == right){
            count++;
            maxlen = max(maxlen,count);
        }
        else{
            count = 0;
            left = right;
        }
    }

    cout << maxlen + 1;
}
