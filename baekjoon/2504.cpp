/*
[괄호의값]
date: 24.06.21
분야: stack

char에 1자리수 이상의 정수를 저장하려 해서 틀림.
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input;
    stack<int> s;
    int answer = 0;

    cin >> input;

    for (char c : input)
    {
        if (c == '(' || c == '[')
            s.push(c*-1);
        else if (c == ')')
        {
            int tmp = 0;
            while (true)
            {
                if (s.empty() || s.top() == '['*-1 || s.top() == ']'*-1)
                {
                    cout << 0;
                    return 0;
                }
                else if (s.top() == '('*-1)
                {
                    if (tmp == 0)
                        tmp = 2;
                    else
                        tmp *= 2;
                    s.pop();
                    s.push(tmp);
                    break;
                }
                else
                {
                    //cout<< "tmp(before):" << tmp;
                    tmp += s.top();
                    //cout<< " tmp(after):" << tmp << endl;
                    s.pop();
                }
            }
        }
        else if (c == ']')
        {
            int tmp = 0;
            while (true)
            {
                if (s.empty() || s.top() == '('*-1 || s.top() == ')'*-1)
                {
                    cout << 0;
                    return 0;
                }
                else if (s.top() == '['*-1)
                {
                    if (tmp == 0)
                        tmp = 3;
                    else
                        tmp *= 3;
                    s.pop();
                    s.push(tmp );
                    break;
                }
                else
                {
                    //cout<< "tmp(before):" << tmp;
                    tmp += s.top();
                    //cout<< " tmp(after):" << tmp << endl;
                    s.pop();
                }
            }
        }
    }

    while(!s.empty()){
        if(s.top() == '('*-1 || s.top() == '['*-1 || s.top() == ')'*-1 || s.top() == ']'*-1){
            cout << 0;
            return 0;
        }
        answer += s.top();
        s.pop();
    }

    cout << answer;
    return 0;
}

/*
(()[[]])([])
(() -> 2                    | (2
(()[[] -> 2 3               | (2[3
(()[[]] -> 2 3*3            | (2 9   // ] 등장 시, 스택에서 [가 나올 때 까지 찾고 안에 있는 거 다 더한 다음에 3을 곱함..
(()[[]]) -> (2+3*3)*2       | 22
(()[[]])([] -> (2+3*3)*2    | 22 (3
(()[[]])([]) -> (2+3*3)*2   | 28


 */