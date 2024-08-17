/* 
[숨바꼭질]
- date: 24.08.14
- 분류: Graph
- 풀이: BFS + 거리 구하기
 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
int vis[20001];
vector<int> adj[20001];
queue<int> Q;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vis[1] = 1;
    Q.push(1);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(auto next: adj[cur]){
            if(vis[next]>0)continue;
            vis[next] = vis[cur] + 1;
            Q.push(next);
        }
    }

    // cout << "vis: ";
    // for(int i = 1; i <= N; i++){
    //     cout << vis[i] << ' ';
    // }
    // cout << '\n';

    int* max_distance_pointer = max_element(vis+1,vis+1+N);
    int first_max_distance_node = max_distance_pointer - vis;
    int max_distance = *max_element(vis+1,vis+1+N);
    int max_distance_node_cnt = 0;
    for(int i = first_max_distance_node; i <= N; i++){
        if(vis[i] == max_distance) max_distance_node_cnt++;
    }

    cout << first_max_distance_node << ' ' << max_distance-1 << ' ' << max_distance_node_cnt;

    return 0;
}