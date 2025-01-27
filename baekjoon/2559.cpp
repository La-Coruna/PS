/*
[수열] 
- date: 25.01.27
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K, max_sum, sum = 0;
    cin >> N >> K;
    vector<int> nums(N);
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }

    for(int i = 0; i < K; i++){
        sum += nums[i];
    }

    max_sum = sum;
    for(int i = K; i < N; i++){
        sum += nums[i] - nums[i-K];
        max_sum = max(max_sum, sum);
    }

    cout << max_sum;

    return 0;
}