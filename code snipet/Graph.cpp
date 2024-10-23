#include <bits/stdc++.h>
using namespace std;

// BFS
namespace BFS{
    vector<int> adj[10];
    bool vis[10];
    void bfs(){
        queue<int> Q;
        vis[1] = true;
        Q.push(1);
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            cout << cur << ' ';
            for(int nxt: adj[cur]){
                if(vis[nxt]) continue;
                vis[nxt] = true;
                Q.push(nxt);
            }
        }
    }
}

// DFS
// stack에서 꺼낸 후 방문여부를 체크해주는 것이 중요.
namespace DFS{
    vector<int> adj[10];
    bool vis[10];

    void dfs(){
        stack<int> S;
        S.push(1);
        while(!S.empty()){
            int cur = S.top(); S.pop();
            if(vis[cur]) continue;
            vis[cur] = true;
            cout << cur << ' ';
            for(int nxt: adj[cur]){
                if(vis[nxt]) continue;
                S.push(nxt);
            }
        }
    }
}

// DFS
namespace DFS_with_recursion{
    vector<int> adj[10];
    bool vis[10];

    void dfs(int cur){
        vis[cur] = true; // dfs(nxt) 호출 앞에 vis[nxt]하는 식으로 하면, 첫 노드를 방문 체크 못 해줌.
        cout << cur << ' ';
        for(int nxt: adj[cur]){
            if(vis[nxt]) continue;
            dfs(nxt);
        }
    }
}

// Dijkstra
namespace Dijkstra{
    #define X first
    #define Y second
    int V, E, K; // 정점 개수, 간선 개수, 시작 정점
    vector<pair<int,int>> adj[20'001];

    vector<int> dijkstra(int K){
        vector<int> min_dist(V+1,0x7fffffff);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        min_dist[K] = 0;
        pq.emplace(0,K);

        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            if(cur.X != min_dist[cur.Y]) continue;
            for(auto nxt: adj[cur.Y]){
                int nxt_dist = d[cur.Y] + nxt.X;
                if(nxt_dist < min_dist[nxt.Y]){
                    min_dist[nxt.Y] = nxt_dist;
                    pq.emplace(nxt_dist, nxt.Y);
                }
            }
        }
        return min_dist;
    }
}

// Dijkstra with path
namespace Dijkstra_with_path{
    #define X first
    #define Y second
    int V, E, K; // 정점 개수, 간선 개수, 시작 정점
    vector<pair<int,int>> adj[20'001];
    int pre[20'001];

    vector<int> dijkstra(int K){
        vector<int> min_dist(V+1,0x7fffffff);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        min_dist[K] = 0;
        pq.emplace(0,K);

        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            if(cur.X != min_dist[cur.Y]) continue;
            for(auto nxt: adj[cur.Y]){
                int nxt_dist = cur.X + nxt.X;
                if(nxt_dist < min_dist[nxt.Y]) continue;
                min_dist[nxt.Y] = nxt_dist;
                pq.emplace(nxt_dist, nxt.Y);
                pre[cur.Y] = nxt.Y;
            }
        }
        return min_dist;
    }
}

namespace UnionFind{
    vector<int> parent;

    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y)
            return;
        parent[y] = x;
    }

    bool isUnion(int x, int y){
        return find(x) == find(y);
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}