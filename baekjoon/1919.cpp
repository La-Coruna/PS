/* 
date: 24.05.28
분야: 배열
 */
#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int alphabet[26] = {0};
    string str1, str2;
    int answer = 0;

    cin >> str1 >> str2;

    for(auto c: str1){
        alphabet[c-'a']++;
    }
    for(auto c: str2){
        alphabet[c-'a']--;
    }
    for(auto i: alphabet){
        if(i!=0){
            answer += abs(i);
        }
    }

    cout << answer;

    return 0;
}