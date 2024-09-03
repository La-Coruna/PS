/* 
[최단경로]
- date: 24.09.03
- 분류: Dijkstra
 */

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

#define INF 4'000'000

int V, E, K;
vector<pair<int,int>> adj[20'001];
priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
int d[20'001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E >> K;

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w,v);
    }
    fill(d+1, d+1+V, INF);

    d[K] = 0;
    pq.push({0,K});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int cur_dist = cur.X, cur_idx = cur.Y;
        if(cur_dist != d[cur_idx]) continue;
        for(auto e: adj[cur_idx]){
            int nxt_dist = cur_dist + e.X, nxt_idx = e.Y;
            if(nxt_dist >= d[nxt_idx]) continue;
            d[nxt_idx] = nxt_dist;
            pq.push({nxt_dist, nxt_idx});
        }
    }

    for(int i = 1; i <= V; i++){
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }
    
    return 0;
}