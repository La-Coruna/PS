/*
[서로 다른 부분 문자열의 개수] 
- date: 25.04.12
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<string> mySet;
    string S;
    cin >> S;

    for(int st = 0; st < S.length(); st++){
        for(int cnt = 1; cnt <= S.length() - st; cnt++)
            mySet.emplace(S.substr(st,cnt));
    }

    cout << mySet.size();

    return 0;
}