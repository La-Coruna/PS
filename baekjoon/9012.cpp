/* 
[괄호]
- date: 24.06.22
- 분류: Stack
*/
#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    while(N--){
        stack<char> s;
        bool isValid = true;
        string input;

        cin >> input;

        for(char c: input){
            if(c == '(')
                s.push(c);
            else{ // ')' 인 경우
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else{
                    isValid = false;
                    break;
                }
            }
        }
        if(!s.empty())
            isValid = false;
        
        if(isValid)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}