/*
[전깃줄] 
- date: 26.01.07

- 전기줄 수 N = 100

- 1. 가장 큰 부분수열의 길이 X 구하기. -> O(NlgN)
- 2. 전체 전깃줄 수에서 X를 빼면, 그것이 제거해야하는 최소 전기줄 수
*/
#include <bits/stdc++.h>
using namespace std;

int N;
int dp[101];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<pair<int,int>> arr;
    for(int i = 0; i < N; i++){
        int u, v;
        cin >> u >> v;
        arr.emplace_back(u,v);
    }

    // 1. 왼쪽 번호로 정렬
    sort(arr.begin(), arr.end());

    // 2. 가장 큰 부분수열의 길이 X 구하기. -> DP
    int cur_max_length = 0;
    for(int i = 0; i < N; i++){
        int cur_value = arr[i].second;
        auto a = lower_bound(dp, dp+cur_max_length, cur_value);

        // 값이 없거나, 더 작으면 갱신
        if(*a == 0){
            *a = cur_value;
            cur_max_length++;
        }   
        else if(cur_value < *a) *a = cur_value;
    }

    cout << N - cur_max_length;
    
    return 0;
}