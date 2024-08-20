/* 
[잃어버린 괄호]
- date: 24.08.19
- 분류: String
 */

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    bool isPlus = true;
    string num = "";
    int result = 0;

    for(char c: input){
        if(c == '+') {
            if(isPlus) {
                result += stoi(num);
                num = "";
            } else {
                result -= stoi(num);
                num = "";
            }
        }
        if(c == '-') {
            if(isPlus) {
                result += stoi(num);
                num = "";
            } else {
                result -= stoi(num);
                num = "";
            }
            isPlus = false;
        }
        else{
            num += c;
        }
    }
    if(isPlus) {
        result += stoi(num);
        num = "";
    } else {
        result -= stoi(num);
        num = "";
    }

    cout << result;

    return 0;
}