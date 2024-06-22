#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

// 문제에서 주어질 보드.
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 필요한 변수들 선언 및 초기화
    bool vis[512][512];
    int n = 7, m = 10;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    queue<pair<int,int>> Q;

    // 첫 시작점 설정
    vis[0][0] = true;
    Q.push({0,0});

    // BFS 탐색 시작
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = true;
            Q.push({nx,ny});
        } 
    }

    return 0;
}

/* 
<주의 사항>
1. 시작점의 방문 표시 했는지 체크
2. 큐에 좌표를 넣을 때 방문했다고 표시해야 힘. 큐에서 뺄 때 하면 같은 칸이 큐에 여러번 들어감.
3. nx, ny가 배열 바깥을 벗어났는지 확인.
 */