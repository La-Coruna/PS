/*
[인구 이동] 
- date: 24.01.28
- 분류: bfs
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N, L, R;
int A[50][50];
int vis[50][50];

bool BFS(int x, int y){
    vector<pair<int,int>> V;

    vis[x][y] = true;
    V.emplace_back(x,y);

    int sum = A[x][y];
    int cnt = 1;

    for(int k = 0; k < V.size(); k++){
        auto cur = V[k];
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0||ny < 0||nx >= N||ny >= N) continue;
            if(vis[nx][ny]) continue;
            int diff = abs(A[cur.X][cur.Y] - A[nx][ny]);
            if(diff < L || diff > R) continue;

            vis[nx][ny] = true;
            V.emplace_back(nx,ny);
            sum += A[nx][ny];
            cnt++;
        }
    }
    int div = sum / cnt;
    for(auto cur : V){
        A[cur.X][cur.Y] = div;
    }
    return cnt > 1;
}

bool SpendADay(){
    bool hasMove = false;

    for(int i = 0; i < N; i++)
        fill(vis[i], vis[i]+N, false);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(vis[i][j]) continue;
            hasMove |= BFS(i,j);
        }
    }
    return hasMove;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    int days = 0;
    while(SpendADay())
        days++;

    cout << days;

    return 0;
}