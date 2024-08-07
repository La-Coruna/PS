/* 
[케빈 베이컨의 6단계 법칙]
- date : 24.08.06
- 분류: Graph
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, answer, min_score = 100000;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for(int i = 1; i <= N; i++){
        int vis[101] = {0};
        queue<int> Q;
        int score = 0;

        vis[i] = 1;
        Q.push(i);
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(auto next: adj[cur]){
                if(vis[next] > 0) continue;
                vis[next] = vis[cur] + 1;
                Q.push(next);
                score += vis[cur];
            }
        }

        if(score < min_score){
            min_score = score;
            answer = i;
        }
    }

    cout << answer;

    return 0;
}