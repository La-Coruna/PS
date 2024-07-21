/* 
[감시]
- date: 24.07.19
- 분류: Simulation
 */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M, K, answer = 64;
int board[8][8];
int vis[8][8];
pair<int,int> cctv[8];
int maxTrial[6] = {0,4,2,4,4,1};

void MonitorD(int, int, int);
void MonitorU(int, int, int);
void MonitorR(int, int, int);
void MonitorL(int, int, int);
void Monitor(int, int, int, int, int);
void MonitorLoop(int);
int CountBlindSpot();
void printBoard();

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6){
                cctv[K] = make_pair(i,j);
                K++;
            }
        }
    }

    MonitorLoop(0);
    cout << answer;

    return 0;
}


// cctv
void MonitorD(int x, int y, int d){
    for(int i = x; i < N; i++){
        if(board[i][y] == 6) break;
        vis[i][y] += d;
    }
}
void MonitorU(int x, int y, int d){
    for(int i = x; i >= 0; i--){
        if(board[i][y] == 6) break;
        vis[i][y] += d;
    }
}
void MonitorR(int x, int y, int d){
    for(int i = y; i < M; i++){
        if(board[x][i] == 6) break;
        vis[x][i] += d;
    }
}
void MonitorL(int x, int y, int d){
    for(int i = y; i >= 0; i--){
        if(board[x][i] == 6) break;
        vis[x][i] += d;
    }
}

void Monitor(int x, int y, int type, int trial, int d){
    if(type == 1){
        if(trial == 1) MonitorR(x,y,d);
        else if(trial == 2) MonitorL(x,y,d);
        else if(trial == 3) MonitorU(x,y,d);
        else MonitorD(x,y,d);
    }
    else if(type == 2){
        if(trial == 1) {MonitorR(x,y,d); MonitorL(x,y,d);}
        else if(trial == 2) {MonitorU(x,y,d); MonitorD(x,y,d);}
    }
    else if(type == 3){
        if(trial == 1) {MonitorR(x,y,d); MonitorU(x,y,d);}
        else if(trial == 2) {MonitorL(x,y,d); MonitorU(x,y,d);}
        else if(trial == 3) {MonitorR(x,y,d); MonitorD(x,y,d);}
        else {MonitorL(x,y,d); MonitorD(x,y,d);}
    }
    else if(type == 4){
        if(trial == 1) {MonitorR(x,y,d); MonitorL(x,y,d); MonitorU(x,y,d);}
        else if(trial == 2) {MonitorR(x,y,d); MonitorL(x,y,d); MonitorD(x,y,d);}
        else if(trial == 3) {MonitorU(x,y,d); MonitorD(x,y,d); MonitorR(x,y,d);}
        else {MonitorU(x,y,d); MonitorD(x,y,d); MonitorL(x,y,d);}
    }
    else {
        MonitorR(x,y,d); MonitorL(x,y,d); MonitorU(x,y,d); MonitorD(x,y,d);
    }
    return;
}

void MonitorLoop(int cctvIdx){
    if(cctvIdx == K){
        answer = min(answer, CountBlindSpot());
        return;
    }
    int x = cctv[cctvIdx].X;
    int y = cctv[cctvIdx].Y;
    int type = board[x][y];
    int trialEnd = maxTrial[type];
    for(int i = 1; i <= trialEnd; i++){
        Monitor(x, y, type, i, 1);
        MonitorLoop(cctvIdx+1);
        Monitor(x, y, type, i, -1);
    }
    return;
}

int CountBlindSpot(){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(vis[i][j]||board[i][j] == 6) continue;
            cnt++;
        }
    }
    //cout << "------<"<< cnt <<">------\n";
    //printBoard();
    return cnt;
}

void printBoard(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] == 0 && vis[i][j] != 0) cout << "# ";
            else cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "----------------\n";
}