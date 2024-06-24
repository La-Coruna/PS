/* 
[숨바꼭질]
- date: 24.06.24
- 분류: BFS

- 범위 체크를 까먹으면 안된다! 안 그러면 vis[next]를 잘 못 접근해서 segment fault가 일어남.
- if(next < 0 || next > 100000) continue;
*/

#include <bits/stdc++.h>

using namespace std;

int vis[100002];
queue<int> Q;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vis[N] = 1; // 시작점을 1로 해서, 마지막 결과에서 1을 빼줘야 함.
    Q.push(N);
    
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur == K) break;
        for(int next: {cur+1, cur-1, cur*2}){
            if(next < 0 || next > 100000) continue;
            if(vis[next] > 0) continue;
            vis[next] = vis[cur] + 1;
            Q.push(next);
        }
    }

    cout << vis[K] -1;

    return 0;
}