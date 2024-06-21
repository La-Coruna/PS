/* 
[균형잡힌 세상]
- date: 24.06.21
- 분류: Stack
*/

#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input;
    getline(cin, input);
    while(input != "."){
        stack<char> s;
        bool isBalanced = true;

        for(char a: input){
            if(a == '(')
                s.push(a);
            else if(a == ')'){
                if(s.empty() || s.top() != '('){
                    isBalanced = false;
                    break;
                }
                s.pop();
            }
            else if(a == '[')
                s.push(a);
            else if(a == ']'){
                if(s.empty() || s.top() != '['){
                        isBalanced = false;
                        break;
                }
                s.pop();
            }
        }

        if(!s.empty()){
            isBalanced = false;
        }
        
        if(isBalanced)
            cout << "yes\n";
        else
            cout << "no\n";

        getline(cin, input);
    }

    return 0;
}