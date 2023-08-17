/* 
date: 0817
분류: dp
소감: 11053(새로 짠 버전)을 응용해서 함.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, input, answer;
    vector<int> arr;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        arr.emplace_back(input);
    }

    vector<int> dp_up(N, 0); // dp_up[a]=b // a번째 숫자를 마지막으로 하는 증가하는 수열의 최대 길이는 b이다.
    vector<int> dp_down(N, 0); // dp_up[a]=b // a번째 숫자를 처음으로 하는 감소하는 수열의 최대 길이는 b이다.

    dp_up[0] = 1;
    dp_down[N-1] = 1;
    for(int i = 1; i < N; i++){
        // 증가하는 수열
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp_up[i] = max(dp_up[i],dp_up[j]);
            }
        }
        ++dp_up[i];
    }
    for(int i = N-2; i >= 0; i--){
        // 감소하는 수열
        for(int j = N-1; j > i; j--){
            if(arr[i] > arr[j]){
                dp_down[i] = max(dp_down[i],dp_down[j]);
            }
        }
        ++dp_down[i];
    }

    answer = 1;
    for(int i = 0; i < N; i++){
        answer = max(answer, dp_up[i]+dp_down[i]-1);
    }

    cout << answer;

    return 0;
}