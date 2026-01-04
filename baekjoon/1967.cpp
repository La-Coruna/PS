/*
[트리의 지름] 
- date: 24.01.04

- 가장 긴 두 노드사이의 거릭 구하기
- n = 10'000 = 10^4
- O(n^2)까지 해도 괜찮
- 노드 하나 잡고, dfs 한번 하는데 O(V+E) = O(V+V-1) = O(V)
- 즉, 모든 노드에 대해서 dfs 돌릴 수 있음.
- 그러면 트리의 지름을 구하기 위해서, leaf node에서 모두 dfs 돌려서 거리 계산해도 충분히 통과 가능하다.
---------------------------------------------------------------------
- 트리의 지름을 구하는 효율적인 방법은, dfs 2번으로 구현할 수 있다.
- 아무 점O 에서 가장 먼 점 A 구하기
- 아무 점A 에서 가장 먼 점 B 구하기
- A와 B 사이의 거리가 트리의 지름이다.

*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> adj[10'001];


pair<int,int> dfs(int cur, int par){
    int distance = 0, endNode = cur;
    for(auto nxt: adj[cur]){
        if(nxt.first == par) continue;
        auto [dist, end] = dfs(nxt.first, cur);
        int newDistance = nxt.second + dist;
        if(newDistance > distance){
            distance = newDistance;
            endNode = end;
        }
    }
    return make_pair(distance, endNode);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }

    auto [Ato1, A] = dfs(1,-1);
    auto [ans, B] = dfs(A,-1);

    cout << ans;

    return 0;
}