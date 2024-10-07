/* 
[최소비용 구하기 2]
- date: 24.09.26
- 분류: Dijkstra
 */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int,int>> adj[1'001];
int d[1'001];
priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> pq;
int pre[1'001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, st, en;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w,v);
    }
    cin >> st >> en;
    
    fill(d,d+1'001, 0x7fffffff);
    d[st] = 0;
    pq.emplace(0,st);

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(cur.X != d[cur.Y]) continue;
        for(auto nxt: adj[cur.Y]){
            int nxt_dist = cur.X + nxt.X;
            if(nxt_dist >= d[nxt.Y]) continue;
            d[nxt.Y] = nxt_dist;
            pq.emplace(nxt_dist, nxt.Y);
            pre[nxt.Y] = cur.Y;
        }
    }
    // for(int i = 1; i <= n; i++) cout << d[i] << ' ';
    // cout << '\n';
    // for(int i = 1; i <= n; i++) cout << pre[i] << ' ';
    // cout << '\n';

    int cur = en;
    vector<int> path;
    while(true){
        path.emplace_back(cur);
        if(cur == st) break;
        cur = pre[cur];
    }
    cout << d[en] << '\n' << path.size() << '\n';
    for(auto iter = path.rbegin(); iter != path.rend(); iter++) cout << *iter << ' ';

    return 0;
}