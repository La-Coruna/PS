/*
[후위 표기식] 
- date: 26.01.17
*/
#include <bits/stdc++.h>
using namespace std;

string answer;
stack<char> S;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char c;
    while(cin >> c){
        switch (c){
            case '+':
            case '-':
                while(!S.empty() && S.top()!='('){
                    answer += S.top();
                    S.pop();
                }
                S.emplace(c);
                break;
            case '*':
            case '/':
                while(!S.empty() && S.top()!='(' && S.top()!='+' && S.top()!='-'){
                    answer += S.top();
                    S.pop();
                }
                S.emplace(c);
                break;
            case '(':
                S.emplace(c);
                break;
            case ')':
                while(!S.empty() && S.top()!='('){
                    answer += S.top();
                    S.pop();
                }
                S.pop();
                break;
            default:
                S.emplace(c);
                break;
        }
    }

    while(!S.empty()){
        answer += S.top();
        S.pop();
    }

    cout << answer;

    return 0;
}