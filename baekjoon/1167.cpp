/*
[트리의 지름] 
- date: 26.01.09
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100'000];

// 제일 먼 node, 그 거리
pair<int,int> dfs(int cur, int par){
    int farthest_node = cur, total_cost = 0;
    for(auto [nxt_node, curToNxt_cost]: adj[cur]){
        if(nxt_node == par) continue;
        auto [n, c] = dfs(nxt_node, cur);
        c+= curToNxt_cost;
        if(c > total_cost) {
            farthest_node = n;
            total_cost = c;
        }
    }
    return make_pair(farthest_node, total_cost);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int V;

    cin >> V;

    int u, v, w;
    for(int i = 1; i <= V; i++){
        cin >> u >> v;
        while(v != -1){
            cin >> w;
            adj[u].emplace_back(v,w);
            cin >> v;
        }
    }

    auto [A, Ato1_cost] = dfs(1,-1);
    auto [B, AtoB_cost] = dfs(A,-1);

    cout << AtoB_cost;

    return 0;
}