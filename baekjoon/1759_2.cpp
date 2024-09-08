/* 
[암호 만들기]
- date: 24.09.08
- 분류: Backtracking
- stl::next_permutation()으로 풀어봄.
 */

#include <bits/stdc++.h>
using namespace std;
int L, C;
int vowel = 0;
char arr[15], ans[15];
bool issued[15];
vector<string> answer;

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    for(int i = 0; i < C; i++){
        cin >> arr[i];
    }
    sort(arr, arr + C);

    // C개 중에 L개 뽑기, C-L개의 0과 L개의 1
    for(int i = C-L; i < C; i++)
        issued[i] = true;

    do{
        string s;
        int idx = 0, vowel = 0;
        for(int i = 0; i < C; i++){
            if(!issued[i]) continue;
            if(isVowel(arr[i])) vowel++;
            ans[idx++] = arr[i];
        }
        if(vowel < 1 || L - vowel < 2) continue;
        for(int i = 0; i < L; i++)
            s += ans[i];
        answer.emplace_back(s);
    }while(next_permutation(issued, issued + C));

    for(auto iter = answer.rbegin(); iter != answer.rend(); iter++)
        cout << *iter << '\n';

    return 0;
}