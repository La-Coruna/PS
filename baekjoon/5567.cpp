/* 
[결혼식]
- date: 24.08.05
- 분류: Graph
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[505];
int vis[505];
queue<int> Q;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, answer = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vis[1] = 1;
    Q.push(1);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(auto next : adj[cur]){
            if(vis[next] != 0) continue;
            vis[next] = vis[cur] + 1;
            answer++;
            if(vis[next] < 3) Q.push(next);
        }
    }
    cout << answer;

    return 0;
}
/* 
상근이: vis = 1
상근이 친구: vis = 2
상근이 친구의 친구: vis = 3
 */