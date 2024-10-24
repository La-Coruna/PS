/*
[구슬 찾기] 
- date: 24.10.25
- 분류: Graph
- "나보다 무거운 구슬이 (N+1)/2개보다 같거나 많이 있나? 그럼 out"
- "나보다 가벼운 구슬이 (N+1)/2개보다 같거나 많이 있나? 그럼 out"
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> heavy(100);
vector<vector<int>> light(100);

int bfs(int cur, vector<vector<int>>& adj){
    int cnt = 0;
    queue<int> Q;
    bool vis[100] = {0};

    vis[cur] = true;
    Q.emplace(cur);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        cnt++;
        for(int nxt : adj[cur]){
            if(vis[nxt]) continue;
            vis[nxt] = true;
            Q.emplace(nxt);
        }
    }
    return cnt-1;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;

    int N, M, a;
    cin >> N >> M;
    a = (N+1)/2;
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        heavy[u].emplace_back(v);
        light[v].emplace_back(u);
    }


    for(int i = 1; i <= N; i++){
        if(bfs(i, heavy) >= a) ans++;
        else if(bfs(i, light) >= a) ans++;
    }

    cout << ans;

    return 0;
}