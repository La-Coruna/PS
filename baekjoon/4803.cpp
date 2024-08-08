/* 
[트리]
- date: 24.08.08
- 분류: Tree
 */
#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int caseNum = 1;
    while(true){
        int N, M;
        cin >> N >> M;
        if(N == 0) break;

        vector<int> adj[501];
        for(int i = 0; i < M; i++){
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        int par[501] = {0};
        bool vis[501] = {0};
        queue<int> Q;
        int treeNum = 0;

        for(int i = 1; i <= N; i++){
            bool isTree = true;
            if(vis[i]) continue;
            
            vis[i] = true;
            Q.push(i);
            while(!Q.empty()){
                int cur = Q.front(); Q.pop();
                //cout << cur << " -> ";
                for(auto next : adj[cur]){
                    if(next == par[cur]) continue;
                    if(vis[next]) {
                        isTree = false;
                        //cout << "It's not Tree! \n";
                        break;
                    }
                    par[next] = cur;
                    vis[next] = true;
                    Q.push(next);
                }
            }
            if(isTree) treeNum++;
        }

        cout << "Case " << caseNum << ": ";
        if(treeNum == 0) cout << "No trees.\n";
        else if(treeNum == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << treeNum << " trees.\n";

        caseNum++;
    }

    return 0;
}