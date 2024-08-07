/* 
[바이러스]
- date: 24.08.05
- 분류: Graph
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool vis[101];
queue<int> Q;


int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, answer = 0;
    cin >> N >> M;
    while(M--){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vis[1] = true;
    Q.push(1);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(auto next: adj[cur]){
            if(vis[next]) continue;
            vis[next] = true;
            Q.push(next);
            answer++;
        }
    }
    
    cout << answer;

    return 0;
}