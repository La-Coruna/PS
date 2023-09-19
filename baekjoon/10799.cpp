#include <iostream>
#include <stack>

using namespace std;

int main(void){

    string input;
    stack<bool> s;
    int res = 0;

    cin >> input;

    for(int i = 0; i < input.size(); i++){
        if(input[i] == '(')
            s.push(true);
        if(input[i] == ')'){
            // top이 '('인 경우
            if(input[i-1] == '('){
                s.pop();
                res += s.size();
                //cout << "size: " << s.size() << "res: " << res << endl;
            }
            // top이 ')'인 경우
            if(input[i-1] == ')'){
                s.pop();
                res++;
            }
        }
    }

    cout << res;
    

    return 0;
}