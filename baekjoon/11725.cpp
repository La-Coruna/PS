/* 
[트리의 부모 찾기]
- date: 24.08.07
- 분류: Tree
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int par[100001];
queue<int> Q;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    Q.push(1);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(auto next : adj[cur]){
            if(par[cur] == next) continue;
            par[next] = cur;
            Q.push(next);
        }
    }

    for(int i = 2; i <= N; i++){
        cout << par[i] << '\n';
    }

    return 0;
}