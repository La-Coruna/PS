/* 
[제로]
- date: 24.06.01
- 분류: stack
 */

#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int K;
    int num;
    stack<int> nums;
    int answer = 0;

    cin >> K;
    while(K--){
        cin >> num;
        if (num != 0)
            nums.push(num);
        else {
            nums.pop();
        }
    }
    while(!nums.empty()){
        answer += nums.top();
        nums.pop();
    }
    cout << answer;

    return 0;
}