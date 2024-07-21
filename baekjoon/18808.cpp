/* 
[스티커 붙이기]
- date: 24.07.21
- 분류: Simulation
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, K;

int R[100];
int C[100];
bool sticker[100][10][10];

bool vis[40][40];

bool SizeCheck(int stickerIdx){
    int r = R[stickerIdx], c = C[stickerIdx];
    return (r > N || c > M);
}

bool OOB(int x, int y, int stickerIdx){
    int r = R[stickerIdx], c = C[stickerIdx];
    return (x + r - 1 >= N || y + c - 1 >= M);
}

bool Check(int x, int y, int stickerIdx){
    int r = R[stickerIdx], c = C[stickerIdx];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!sticker[stickerIdx][i][j]) continue;
            if(vis[x+i][y+j]) return false;
        }
    }
    return true;
}

void Attach(int x, int y, int stickerIdx){
    for(int i = 0; i < R[stickerIdx]; i++){
        for(int j = 0; j < C[stickerIdx]; j++){
            if(sticker[stickerIdx][i][j]) vis[x+i][y+j] = sticker[stickerIdx][i][j];
        }
    }
}

void TurnSticker(int stickerIdx){
    int tmp[10][10] = {0};
    for(int j = 0; j < C[stickerIdx]; j++){
        for(int i = R[stickerIdx]-1; i >= 0; i--){
            tmp[j][R[stickerIdx]-1-i] = sticker[stickerIdx][i][j];
        }
    }
    for(int i = 0; i < C[stickerIdx]; i++){
        for(int j = 0; j < R[stickerIdx]; j++){
            sticker[stickerIdx][i][j] = tmp[i][j];
        }
    }
    int tmpR = R[stickerIdx];
    R[stickerIdx] = C[stickerIdx];
    C[stickerIdx] = tmpR;
}

bool CheckAndAttach(int stickerIdx){
    if (SizeCheck(stickerIdx)) return false;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(OOB(i,j,stickerIdx)) break;
            if(Check(i,j,stickerIdx)) {
                Attach(i,j,stickerIdx);
                return true;
            }
        }
    }
    return false;
}

int CountAttached(){
    int res = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(vis[i][j]) res++;
        }
    }
    return res;
}

void PrintBoard(){
    cout << "---[board]---\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "-------------\n";
}

void PrintSticker(int stickerIdx){
    cout << "sticker<" << stickerIdx << ">\n";
        for(int x = 0; x < R[stickerIdx]; x++){
            for(int y = 0; y < C[stickerIdx]; y++){
            cout << sticker[stickerIdx][x][y] << ' ';
        }
        cout << '\n';
    }
    cout << "--------\n";
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i = 0; i < K; i++){
        cin >> R[i] >> C[i];
        for(int x = 0; x < R[i]; x++){
            for(int y = 0; y < C[i]; y++){
                cin >> sticker[i][x][y];
            }
        }
    }
    for(int i = 0; i < K; i++){
        for(int j = 0; j < 4; j++){
            //PrintSticker(i);
            if (CheckAndAttach(i)) break;
            TurnSticker(i);
        }
        //PrintBoard();
    }

    cout << CountAttached();

    return 0;
}