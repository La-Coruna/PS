/*
[최소비용 구하기]
- date: 24.09.30
- 분류: dijkstra
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int,int>> adj[1001];

int dijkstra(int st, int en, int N){
    vector<int> d(N+1,0x7fffffff);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    d[st] = 0;
    pq.emplace(0, st);

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(cur.X != d[cur.Y]) continue;
        for(auto nxt : adj[cur.Y]){
            int nxt_d = cur.X + nxt.X;
            if(nxt_d >= d[nxt.Y]) continue;
            d[nxt.Y] = nxt_d;
            pq.emplace(nxt_d, nxt.Y);
        }
    }

    return d[en];
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, st, en;
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w,v);
    }
    cin >> st >> en;
    
    cout << dijkstra(st, en, N);

    return 0;
}