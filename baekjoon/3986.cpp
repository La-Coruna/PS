/* 
[좋은 단어]
- date: 24.06.22
- 분류: Stack
*/
#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int answer = 0;
    int N;
    cin >> N;
    while(N--){
        stack<char> s;
        string input;
        cin >> input;

        for(char c : input){
            if(s.empty())
                s.push(c);
            else if (s.top() == c){
                s.pop();
            } else{
                s.push(c);
            }
        }

        if(s.empty())
            answer++;
    }
    cout << answer;
    return 0;
}