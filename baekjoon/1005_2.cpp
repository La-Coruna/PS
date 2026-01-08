/*
[ACM Craft] 
- date: 26.01.08

- 위상정렬로 풀 수 있겠다.
- 먼저 지을 수 있는 것부터 지으면서, 그 다음 건물 짓는 비용에 더해주자.
- dp[nxt] = max(dp[nxt], dp[cur] + times[nxt])

- 주의할 점: 건물 짓는 시간이 0인 것도 있다.
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int N, K, W, X, Y;
        int times[1001] = {0}, dp[1001] = {0};
        int indegree[1001] = {0};
        fill(dp, dp+1001, -1);
        vector<int> adj[1001];
        queue<int> Q;
        
        // 1. input
        cin >> N >> K;
        for(int i = 1; i <= N; i++){
            cin >> times[i];
        }
        for(int i = 0; i < K; i++){
            cin >> X >> Y;
            adj[X].emplace_back(Y);
            indegree[Y]++;
        }
        cin >> W;

        // 2. 첫 건물 queue에 넣기
        for(int i = 1; i <= N; i++){
            if(indegree[i] == 0) Q.emplace(i);
            dp[i] = times[i]; // 첫 건물들은 본인 걸리는 시간이 최종 시간
        }

        // 3. 지을 수 있는 건물 지으면서 dp 배열 채우기
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();

            for(int& nxt: adj[cur]){
                if(--indegree[nxt] == 0) Q.emplace(nxt);
                dp[nxt] = max(dp[nxt], dp[cur] + times[nxt]);
            }
        }

        // 3. 정답 출력
        cout << dp[W] << '\n';
    }

    return 0;
}