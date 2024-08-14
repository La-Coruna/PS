/* 
[효율적인 해킹]
- date: 24.08.14
- 분류: Graph
- 풀이: DFS
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
int score[10001] = {0};
int cur_score = 0;
bool vis[10001] = {0};

void dfs(int cur){
    vis[cur] = true;
    cur_score++;
    for(auto next: adj[cur]){
        if(vis[next]) continue;
        dfs(next);
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[v].emplace_back(u);
    }

    for(int i = 1; i <= N; i++){
        cur_score = 0;
        fill(vis+1,vis+1+N,0);
        dfs(i);
        score[i] = cur_score;
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