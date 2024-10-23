/* 
[촌수계산]
- date: 24.10.22
- 분류: Graph, BFS
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
int vis[101];
queue<int> Q;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, x, y;
    cin >> n >> a >> b >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    fill(vis, vis + n+1, -1);
    vis[a] = 0;
    Q.push(a);

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur == b) break;
        for(auto nxt: adj[cur]){
            if(vis[nxt] != -1) continue;
            vis[nxt] = vis[cur] + 1;
            Q.push(nxt);
        }
    }

    cout << vis[b];

    return 0;
}