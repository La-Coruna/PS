/*
[Surrounded Regions] 
- date: 25.09.23
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    bool vis[200][200] = {false};
    queue<pair<int,int>> Q;
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'X' || vis[i][j]) continue;
                
                bool isSurround = true;

                vector<pair<int,int>> path;

                vis[i][j] = true;
                Q.emplace(i,j);
                path.emplace_back(i,j);
                while(!Q.empty()){
                    auto [curX, curY] = Q.front(); Q.pop();
                    for(int d = 0; d < 4; d++){
                        int nx = curX + dx[d], ny = curY + dy[d];
                        // 옆이 가장자리인 경우
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                            isSurround = false;
                            continue;
                        }
                        if(vis[nx][ny] || board[nx][ny] == 'X') continue;
                        vis[nx][ny] = true;
                        Q.emplace(nx,ny);
                        path.emplace_back(nx,ny);
                    }
                }
                if(isSurround){
                    for(auto& [x,y] : path){
                        board[x][y] = 'X';
                    }
                }
            }
        }
    }
};