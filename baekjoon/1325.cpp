/* 
[효율적인 해킹]
- date: 24.08.14
- 분류: Graph
- 풀이: BFS + 영역 크기 구하기
 */
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    vector<int> adj[10001];
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[v].emplace_back(u);
    }

    int score[10001] = {0};
    queue<int> Q;
    for(int i = 1; i <= N; i++){
        bool vis[10001] = {0};
        vis[i] = true;
        Q.push(i);
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(auto next: adj[cur]){
                if(vis[next]) continue;
                vis[next] = true;
                Q.push(next);
                score[i]++;
            }
        }
    }

    // for(int i = 1; i <= N; i++){
    //     cout << score[i] << ' ';
    // }
    // cout << '\n';
    
    int max_score = * max_element(score+1, score+1+N);
    for(int i = 1; i <= N; i++){
        if(score[i] == max_score) cout << i << ' ';
    }

    return 0;
}