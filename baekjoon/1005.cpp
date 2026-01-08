/*
[ACM Craft] 
- date: 26.01.08

- 필승건물 W로부터 역으로 dfs돌리면서 , 재귀적으로 시간을 더 하면 되겠다.
- 현재 건물까지 걸리는 시간 = 이전에 지어야 하는 건물들 중 최대 시간 + 현재 건물 시간
- 교착 상태는 없다고 가정.

- 주의할 점: 건물 짓는 시간이 0인 것도 있다.
*/
#include <bits/stdc++.h>
using namespace std;

int dfs(int cur, const vector<int> (&adj)[1001], int *times, int* dp){
    // 현재 건물까지 짓는 시간을 안다면 바로 리턴
    if(dp[cur] != -1) return dp[cur];

    // 모른다면 계산
    dp[cur] = 0;
    for(int nxt: adj[cur]){
        dp[cur] = max(dp[cur], dfs(nxt, adj, times, dp));
    }
    dp[cur] += times[cur];
    
    return dp[cur];
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int N, K, W, X, Y;
        int times[1001] = {0}, dp[1001];
        fill(dp, dp+1001, -1);
        vector<int> adj_reverse[1001];
        
        // 1. input
        cin >> N >> K;
        for(int i = 1; i <= N; i++){
            cin >> times[i];
        }
        for(int i = 0; i < K; i++){
            cin >> X >> Y;
            adj_reverse[Y].emplace_back(X);
        }
        cin >> W;

        // 3. 정답 출력
        cout << dfs(W,adj_reverse,times,dp) << '\n';
    }

    return 0;
}