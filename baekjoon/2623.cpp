/*
[음악프로그램] 
- date: 24.10.25
- 분류: Graph, topological sorting
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int deg[1001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    while(M--){
        int num, u, v;
        cin >> num;
        cin >> u;
        for(int i = 1; i < num; i++){
            cin >> v;
            adj[u].emplace_back(v);
            deg[v]++;
            u = v;
        }
    }

    vector<int> ans;
    queue<int> Q;
    for(int i = 1; i <= N; i++){
        if(deg[i] == 0) Q.emplace(i);
    }
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        ans.emplace_back(cur);
        for(int nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt]==0) Q.emplace(nxt);
        }
    }
    if(ans.size() != N) cout << 0;
    else{
        for(int e : ans){
            cout << e << '\n';
        }
    }
    

    return 0;
}