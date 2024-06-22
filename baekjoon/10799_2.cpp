/* 
[쇠막대기]
date: 24.06.21
분야: stack
*/
#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int answer = 0;
    string input;
    stack<char> s;
    bool isNextLaser = false;

    cin >> input;
    for(char c : input){
        if(c == '('){
            s.push(c);
            isNextLaser = true;
        }
        else if(c == ')'){
            s.pop();
            if(isNextLaser) answer += s.size();
            else answer++;
            isNextLaser = false;
        }
    }

    cout << answer;

    return 0;
}