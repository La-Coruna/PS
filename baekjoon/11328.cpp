/* 
date: 24.05.27
분야: 배열
 */

#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    int alphabets[26] = {0};
    bool isPossible;
    string str1, str2;

    cin >> N;

    for(int i = 0; i < N; i++){
        isPossible = true;
        fill(alphabets, alphabets+26, 0);
        cin >> str1 >> str2;

        for(auto j : str1){
            alphabets[j - 'a']++;
        }

        for(auto j : str2){
            alphabets[j - 'a']--;
        }

        for(auto j : alphabets){
            if(j != 0)
                isPossible = false;
        }

        if(isPossible)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }

    return 0;
}