/* 
[플로이드 2]
- date: 24.08.31
- 분류: Floyd
 */

#include <bits/stdc++.h>
using namespace std;

int min_cost[101][101];
int nxt[101][101];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        fill(min_cost[i]+1, min_cost[i]+1 + n, 10'000'001);
        min_cost[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        if(c < min_cost[u][v]){
            min_cost[u][v] = c;
            nxt[u][v] = v;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                int new_cost = min_cost[u][i] + min_cost[i][v];
                if(min_cost[u][i] + min_cost[i][v] < min_cost[u][v]){
                    min_cost[u][v] = new_cost;
                    nxt[u][v] = nxt[u][i];
                }
            }
        }
    }
    
    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++){
            cout << ((min_cost[u][v] == 10'000'001) ? 0 : min_cost[u][v]) << ' ';
        }
        cout << '\n';
    }

    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++){
            int cur = nxt[u][v];
            if(cur == 0){
                cout << "0\n";
                continue;
            }

            vector<int> path;
            path.emplace_back(u);
            while(cur != v){
                path.emplace_back(cur);
                cur = nxt[cur][v];
            }
            path.emplace_back(cur);

            cout << path.size();
            for(int n : path)
                cout << ' ' << n;
            cout << '\n';
        }
    }

    return 0;
}