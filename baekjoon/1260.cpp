/* 
[DFS와 BFS]
- date: 24.08.04
- 분류: Graph
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, V;
vector<int> adj[1001];

void input(){
    cin >> N >> M >> V;
    int u, v;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for(int i = 1; i <= N; i++)
        sort(adj[i].begin(), adj[i].end());
}

void bfs(){
    queue<int> Q;
    bool vis[1001];
    fill(vis, vis+1001, false);

    vis[V] = true;
    Q.push(V);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        cout << cur << ' ';
        for(auto next : adj[cur]){
            if(vis[next]) continue;
            vis[next] = true;
            Q.push(next);
        }
    }
    cout << '\n';
}

void dfs(){
    stack<int> S;
    bool vis[1001];
    fill(vis, vis+1001, false);

    S.push(V);

    while(!S.empty()){
        int cur = S.top(); S.pop();
        if(vis[cur]) continue;
        vis[cur] = true;
        cout << cur << ' ';
        for(int i = adj[cur].size() - 1; i >= 0; i--){
            int next = adj[cur][i];
            if(vis[next]) continue;
            S.push(next);
        }
    }
    cout << '\n';
}

bool vis_2[1001];
void dfs2(int cur){
    cout << cur << ' ';
    vis_2[cur] = true;
    for(auto next : adj[cur]){
        if(vis_2[next]) continue;
        dfs2(next);
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    dfs();
    //dfs2(V); cout << '\n';
    bfs();

    return 0;
}