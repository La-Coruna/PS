/*
[줄 세우기]
- date: 24.08.09
- 분류: Topological Sorting
 */
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    vector<int> adj[32001];
    int indegree[32001] = {0};
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        indegree[v]++;
    }

    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0) Q.push(i);
    }
    
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        cout << cur << ' ';
        for(auto next : adj[cur]){
            if(--indegree[next] == 0) Q.push(next);
        }
    }

    return 0;
}