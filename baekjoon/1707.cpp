/* 
[이분 그래프]
- date: 24.08.15
- 분류: Graph

- 순회 하면서 색칠을 함. 인접한 노드 중 이미 방문한 곳이, 같은 색이면 이분 그래프가 안됨.
- 비연결 그래프라면? -> 당근 이 부분도 고려해야함.
- 노드 개수가 홀수인 사이클이 없으면 되는 건가? -> ㅇㅇ
 */
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> K;
    while(K--){
        int V, E;
        cin >> V >> E;
        vector<int> adj[20001];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        int isBipartite = true;
        queue<int> Q;
        bool vis[20001] = {0};
        bool color[20001] = {0};

    for(int i = 1; i <= V; i++){
        if(vis[i] || !isBipartite) continue;
        vis[i] = true;
        color[i] = true;
        Q.push(i);
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            //cout << cur << " -> ";
            for(auto next: adj[cur]){
                if(vis[next]){
                    if (color[next] == color[cur]){
                        isBipartite = false;
                        break;
                    }
                    continue;
                }
                vis[next] = true;
                color[next] = !color[cur];
                Q.push(next);
            }
            if(!isBipartite) break;
        }
    }

        if(isBipartite) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}