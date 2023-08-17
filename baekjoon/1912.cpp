/* 
[연속합]
date: 0817
분류: dp
알고리즘:
sum == 현재까지의 합 (0보다 작아지면 0부터 다시 시작)
answer == 현재까지의 연속된 숫자의 최대 합

<case 1>
input:  10  -4  3  1  5  6  -35  12  21  -1
sum:    10   6  9  10 15 21 -16  12  33  32
answer: 10   10 10 10 15 21  21  21  33  33

<case 2>
input:  -1 -2 -3 -4 -5
sum:    -1 -3 -5             
answer: -1                

<case 3>
input:  -1 -2 5 -4 -5
sum:    -1 -3 5  1 -4
answer: -1 -1 5  5  5

 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, input, sum, answer;

    cin >> n;
    vector<int> dp(n,0);
    cin >> sum;
    answer = sum; // 수열의 길이가 1인 경우 정답이기 때문.
    for(int i = 1; i < n; i++){
        cin >> input;
        if(sum < 0) sum = input;
        else sum += input;
        answer = max(answer,sum);
    }
    
    cout << answer;

    return 0;
}