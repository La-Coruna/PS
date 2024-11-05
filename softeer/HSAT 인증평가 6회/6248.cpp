/*
[출퇴근길] 
- date: 24.11.05
- url: https://softeer.ai/practice/6248
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
vector<int> adj[100'001];
vector<int> adjR[100'001];
bool toCompany[100'001];
bool toCompanyR[100'001];
bool toHome[100'001];
bool toHomeR[100'001];

void bfs(int st, int en, bool* vis){
    queue<int> Q;

    vis[st] = true;
    Q.emplace(st);

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int nxt: adj[cur]){
            if(vis[nxt]) continue;
            if(nxt == en) continue;
            vis[nxt] = true;
            Q.emplace(nxt);
        }
    }
}

void bfsR(int st, bool* vis){
    queue<int> Q;

    vis[st] = true;
    Q.emplace(st);

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int nxt: adjR[cur]){
            if(vis[nxt]) continue;
            vis[nxt] = true;
            Q.emplace(nxt);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adjR[v].emplace_back(u);
    }
    int st, en;
    cin >> st >> en;

    bfs(st, en, toCompany);
    bfsR(st, toCompanyR);
    bfs(en, st, toHome);
    bfsR(en, toHomeR);

    for(int i = 1; i <= n; i++){
        if(toCompany[i] && toCompanyR[i] && toHome[i] && toHomeR[i]) ans++;
    }

    cout << ans;

    return 0;
}