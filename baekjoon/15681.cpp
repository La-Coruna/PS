/*
[트리와 쿼리] 
- date: 24.10.25
- 분류: Graph, Tree
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int p[100001];
int subNodeNum[100001];

int dfs(int cur, int cnt){
    cnt++;
    for(int nxt: adj[cur]){
        if(p[cur] == nxt) continue;
        p[nxt] = cur;
        cnt += dfs(nxt, 0);
    }
    subNodeNum[cur] = cnt;
    return cnt;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, R, Q;
    cin >> N >> R >> Q;
    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(R,0);
    while(Q--){
        int u;
        cin >> u;
        cout << subNodeNum[u] << '\n';
    }

    return 0;
}