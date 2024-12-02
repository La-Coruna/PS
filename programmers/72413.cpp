/*
[합승 택시 요금]
- date: 24.12.02
- url: https://school.programmers.co.kr/learn/courses/30/lessons/72413

떠오른 방법1)
플로이드로 모든 지점 사이의 최단 거리를 구함 -> 200^3 = 8*10^6
각 지점에서 A와 B와 S로의 거리를 더함. 이 값들의 최소값을 찾음
---
떠오른 방법2)
다익스트라로 A와 B와 S에서 모든 지점으로의 거리를 구함. -> 3*(200log200)
---
결국 이 문제는 결국 어떤 지점에서 A,B,S로의 거리의 합이 최소가 되는지 그 지점을 찾는 것.
방법2로 풀음.
*/


#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

vector<pair<int,int>> adj[201];

vector<int> dijkstra(int n, int st){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> d(n+1, 0x7fffffff);
    d[st] = 0;
    pq.emplace(0,st);
    
    while(!pq.empty()){
        int cur_dist, cur_node;
        tie(cur_dist, cur_node) = pq.top(); pq.pop();
        for(auto nxt: adj[cur_node]){
            int nxt_dist = cur_dist + nxt.X, nxt_node = nxt.Y;
            if(nxt_dist >= d[nxt_node]) continue;
            d[nxt_node] = nxt_dist;
            pq.emplace(nxt_dist, nxt_node);
        }
    }
        
    return d;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    // 익숙한 vector<int>adj[n]의 형태로 바꾸기
    for(auto fare: fares){
        int u = fare[0], v = fare[1], w = fare[2];
        adj[u].emplace_back(w,v);
        adj[v].emplace_back(w,u);
    }
    
    // dijkstra로 각 지점에서의 거리 구하기
    vector<int> d_s = dijkstra(n,s);
    vector<int> d_a = dijkstra(n,a);
    vector<int> d_b = dijkstra(n,b);
    
    // 최소 요금 찾기
    int min_cost = 0x7fffffff;
    for(int i = 1; i <= n; i++){
        min_cost = min(min_cost, d_s[i] + d_a[i] + d_b[i]);
    }    
    
    return min_cost;
}