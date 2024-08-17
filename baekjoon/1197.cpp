/* 
[최소 스패닝 트리]
- date: 24.08.11
- 분류: MST
 */
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[10001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back({c,v});
        adj[v].emplace_back({c,u});
    }

    for(int i = 1; i <= V; i++){
        int cur = i;
        for(auto next : adj[cur]){
            cout << i << ' ' << next.second << ' ' << next.first;
        }
        cout << '\n';
    }

    return 0;
}