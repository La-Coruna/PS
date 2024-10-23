/*
[HSAT 1회 정기 코딩 인증평가 기출] 안전운전을 도와줄 차세대 지능형 교통시스템
- date: 24.10.07
- url: https://softeer.ai/class/devcrew/study/resource/detail/description/6274?id=280&resourceId=329
*/
#include <bits/stdc++.h>
using namespace std;

int N, T;
int sign[100][100][4];
bool vis[100][100];
int answer = 0;

// 하 오 상 좌
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<int> nxt_way[13] = {{},
    {0,1,2},{1,2,3},{2,3,0},{3,0,1},
    {1,2},{2,3},{3,0},{0,1},
    {0,1},{1,2},{2,3},{3,0}
};

// x, y, t, d
queue<tuple<int,int,int,int>> Q;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> sign[i][j][0] >> sign[i][j][1] >> sign[i][j][2] >> sign[i][j][3];
        }
    }

    vis[0][0] = true;
    answer++;
    Q.emplace(0,0,0,2);
    while(!Q.empty()){
        int x, y, t, d;
        tie(x, y, t, d) = Q.front(); Q.pop();
        int cur_sign = sign[x][y][t%4];
        // 신호가 달라서 멈춰야 하거나, 시간이 다 된 경우.
        if (d != cur_sign % 4 || t == T) continue;
        for(int nxt_dir: nxt_way[cur_sign]){
            int nx = x + dx[nxt_dir];
            int ny = y + dy[nxt_dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            Q.emplace(nx,ny,t+1,nxt_dir);
            if(vis[nx][ny]) continue;
            vis[nx][ny] = true;
            answer++;
        }
        // 갈 수 있는 곳으로 이동
    }

    cout << answer;

    return 0;
}