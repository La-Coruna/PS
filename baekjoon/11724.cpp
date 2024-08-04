/* 
[연결 요소의 개수]
- date: 24.08.04
- 분류: Graph
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000];
queue<int> Q;
bool vis[1000];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, answer = 0;
    int u, v;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for(int i = 1; i <= N; i++){
        if(vis[i]) continue;
        answer++;
        vis[i] = true;
        Q.push(i);
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(auto next : adj[cur]){
                if(vis[next]) continue;
                vis[next] = 1;
                Q.push(next);
            }
        }
    }

    cout << answer;

    return 0;
}