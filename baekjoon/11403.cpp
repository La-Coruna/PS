/* 
[경로 찾기]
- date: 24.08.05
- 분류: Graph
 */
#include <bits/stdc++.h>
using namespace std;

int adj[100][100];
bool answer[100][100];
queue<int> Q;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> adj[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        int vis[100] = {0};
        vis[i]++;
        Q.push(i);
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(int j = 0; j < N; j++){
                if(!adj[cur][j]) continue;
                if(vis[j] > 1) continue;
                vis[j]++;
                Q.push(j);
                answer[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}