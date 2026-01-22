/*
[가장 긴 증가하는 부분 수열 4] 
- date: 26.01.21

1 ≤ N ≤ 1,000
1 ≤ A ≤ 1,000

dp[i]: 길이가 i인 수열의 마지막 원소

        6
i       0  1  2  3  4  5 
arr     10 20 10 30 20 50
dp      10 20 30 50
pos     0  1  3  5
pre     -1 0  -1 1  -1 3
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXNUM 1001

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, arr[1'000], dp[1'000], pos[1'000], pre[1'000];
    cin >> N;
    fill(pre,pre+N,-1);

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int max_dist = 0;
    for(int i = 0; i < N; i++){
        auto it = lower_bound(dp, dp+max_dist, arr[i]);
        int idx = it - dp;

        if(idx == max_dist) max_dist++;
        *it = arr[i];
        pos[idx] = i;
        pre[i] = (idx>0) ? pos[idx-1] : -1;
    }
    
    cout << max_dist << '\n';
    stack<int> s;
    int cur_idx = pos[max_dist-1];
    while(cur_idx != -1){
        s.emplace(arr[cur_idx]);
        cur_idx = pre[cur_idx];
    }
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}