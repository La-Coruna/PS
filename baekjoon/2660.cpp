/* 
[회장뽑기]
- date: 24.08.05
- 분류: Graph
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[51];
int score[51];
int min_score = 99;
int candidate[51];
int candidateNum = 0;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while(true){
        int u, v;
        cin >> u >> v;
        if(u == -1) break;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for(int i = 1; i <= N; i++){
        queue<int> Q;
        int vis[51] = {0};
        int max_vis = 1;
        vis[i] = 1;
        Q.push(i);
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(auto next : adj[cur]){
                if(vis[next]) continue;
                vis[next] = vis[cur] + 1;
                max_vis = max(max_vis, vis[next]);
                Q.push(next);
            }
        }
        score[i] = max_vis - 1;
        min_score = min(min_score, score[i]);
    }

    for(int i = 1; i <= N; i++){
        if(score[i] != min_score) continue;
        candidate[candidateNum] = i;
        candidateNum++;
    }

    cout << min_score << ' ' << candidateNum << '\n';
    for(int i = 0; i < candidateNum; i++){
        cout << candidate[i] << ' ';
    }

    return 0;
}