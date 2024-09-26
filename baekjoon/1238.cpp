/*
[파티]
- date: 24.09.26
- 분류: Dijkstra
- 각 마을마다 dijkstra를 해주면, O(VElnE)라 1초안에 통과 가능.
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int,int>> adj[1'001];

vector<int> dijkstra(int st){
    vector<int> d(1'001, 0x7fffffff);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    d[st] = 0;
    pq.emplace(0,st);

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(cur.X != d[cur.Y]) continue;
        for(auto nxt: adj[cur.Y]){
            int nxt_d = cur.X + nxt.X;
            if(nxt_d >= d[nxt.Y]) continue;
            d[nxt.Y] = nxt_d;
            pq.emplace(nxt_d, nxt.Y);
        }
    }

    return d;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int max_time = 0;
    int N, M, X;
    cin >> N >> M >> X;

    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w,v);
    }

    vector<int> goHomeTimes = dijkstra(X);
    for(int i = 1; i <= N; i++){
        max_time = max(max_time, dijkstra(i)[X] + goHomeTimes[i]);
    }

    cout << max_time;   

    return 0;
}