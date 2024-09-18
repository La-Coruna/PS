/*
[뱀]
- date: 24.09.18
- 분류: simulation
*/
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define isLeft second
// d가 증가하면 왼쪽으로 회전
int d = 1;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N, K, L, len = 1;

int board[100][100];

queue<pair<int,bool>> change_info;
queue<pair<int,int>> snake;

// void print_board(){
//     for(int i = 0; i < N; i++){
//         for(int j = 0; j < N; j++){
//             cout << board[i][j] << ' ';
//         }
//         cout << '\n';
//     }
//     cout << '\n';
// }

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    // apple
    for(int i = 0; i < K; i++){
        int x, y;
        cin >> x >> y;
        board[x-1][y-1] = 2;
    }
    // change direction
    cin >> L;
    for(int i = 0; i < L; i++){
        int time;
        char dir;
        cin >> time >> dir;
        change_info.emplace(time,dir == 'L' ? true: false);
    }

    int cur_time;
    int cur_x = 0;
    int cur_y = 0;
    board[cur_x][cur_y] = 1;
    snake.emplace(cur_x,cur_y);
    for(cur_time = 1; ;cur_time++){
        cur_x += dx[d];
        cur_y += dy[d];
        // 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
        if(cur_x < 0||cur_y < 0||cur_x >= N||cur_y >= N||board[cur_x][cur_y] == 1){
            // cout << "current time: "<< cur_time << '\n';
            // cout<<"d: "<<d<<", ("<< cur_x << ", " << cur_y << ") board: " << board[cur_x][cur_y] << "\n";
            //print_board();
            break;
        }
        
        // 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
        // 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
        if(board[cur_x][cur_y] != 2){
            auto tail = snake.front();
            board[tail.X][tail.Y] = 0;
            snake.pop();
        }
        // 머리를 다음칸에 위치시킴.
        board[cur_x][cur_y] = 1;
        snake.emplace(cur_x,cur_y);

        // 방향 전환
        // 게임 시작 시간으로부터 X초가 "끝난" 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다
        if(!change_info.empty()){
            auto change = change_info.front();
            if(change.X == cur_time){
                if(change.isLeft) d = (d+1)%4;
                else d = (d+3)%4;
                change_info.pop();
            }
        }

        // cout << "current time: "<< cur_time << '\n';
        // print_board();
    }

    cout << cur_time;


    return 0;
}