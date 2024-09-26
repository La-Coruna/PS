/*
[특정한 최단 경로]
- date: 24.09.26
- 분류: Dijkstra
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int,int>> adj[801];

int cal_dist(int st, int en){
    vector<int> d(801,0x7fffffff);
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

    return d[en];
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, E, v1, v2;
    cin >> N >> E;
    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(c,b);
        adj[b].emplace_back(c,a);
    }
    cin >> v1 >> v2;

    int d1 = cal_dist(1, v1), _d1 = cal_dist(1, v2), d2 = cal_dist(v1, v2), d3 = cal_dist(v2, N), _d3 = cal_dist(v1, N);
    if(d1 == 0x7fffffff || d2 == 0x7fffffff || d3 == 0x7fffffff) cout << -1;
    else cout << min(d1 + d3, _d1 + _d3) + d2;

    return 0;
}