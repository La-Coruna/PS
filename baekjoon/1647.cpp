/*
[도시 분할 계획] 
- date: 25.10.10
*/
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<tuple<int,int,int>> edges;
int p[100'001];

int find(int x){
    if(p[x]<0) return x;
    return p[x] = find(p[x]);
}

bool union_set(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return false;
    if(p[v] < p[u]) swap(u,v);
    else if(p[u] == p[v]) p[u]--;

    p[v] = u;

    return true;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    // 마을이 2개 뿐인 경우
    if(N==2){
        cout << 0;
        return 0;
    }
    // kruskal 알고리즘을 위한 초기화
    edges.reserve(M);
    fill(p, p+1+N, -1);

    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(c,a,b);
    }

    sort(edges.begin(), edges.end());

    int remain_edges = N-2;
    int total_cost = 0;
    for(int i = 0; i < M; i++){
        auto [c,a,b] = edges[i];
        if(union_set(a,b)) {
            total_cost += c;
            if(--remain_edges == 0) break;
        }
    }

    cout << total_cost;

    return 0;
}