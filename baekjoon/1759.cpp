/* 
[암호 만들기]
- date: 24.09.08
- 분류: Backtracking
 */

#include <bits/stdc++.h>
using namespace std;
int L, C;
int vowel = 0;
char arr[15], ans[15];
bool issued[15];

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

void func(int k){
    if(k == L){
        if(vowel < 1 || L-vowel < 2) return;
        for(int i = 0; i < L; i++)
            cout << ans[i];
        cout << '\n';
        return;
    }
    for(int i = 0; i < C; i++){
        if(issued[i] || ans[k-1] > arr[i] ) continue;
        issued[i] = true;
        if(isVowel(arr[i])) vowel++;
        ans[k] = arr[i];
        func(k+1);
        if(isVowel(arr[i])) vowel--;
        issued[i] = false;
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    for(int i = 0; i < C; i++){
        cin >> arr[i];
    }
    sort(arr, arr + C);

    func(0);

    return 0;
}