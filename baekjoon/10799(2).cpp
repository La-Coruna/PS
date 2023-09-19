/* 
date: 0920
분야: stack
- stack 없이 구현해도 될 것 같아서, 그냥 int 변수로 씀.
*/
#include <iostream>

using namespace std;

int main(void){

    string input;
    int s = 0;
    int res = 0;

    cin >> input;

    for(int i = 0; i < input.size(); i++){
        if(input[i] == '(')
            s++;
        if(input[i] == ')'){
            // 바로 전 값이 '('인 경우
            if(input[i-1] == '('){
                s--;
                res += s;
            }
            // 바로 전 값이 ')'인 경우
            if(input[i-1] == ')'){
                s--;
                res++;
            }
        }
    }

    cout << res;

    return 0;
}