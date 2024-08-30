/* 
[플로이드]
- date: 24.08.30
- 분류: Floyd
 */

#include <bits/stdc++.h>
using namespace std;

int min_cost[101][101];

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
        min_cost[u][v] = min(min_cost[u][v],c);
    }

    for(int i = 1; i <= n; i++){
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                min_cost[u][v] = min(min_cost[u][v], min_cost[u][i] + min_cost[i][v]);
            }
        }
    }
    
    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++){
            cout << ((min_cost[u][v] == 10'000'001) ? 0 : min_cost[u][v]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}