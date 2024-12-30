/* 
[숨바꼭질 3]
- date: 24.12.30
- 분류: bfs

- 순간이동할 때 0초가 걸리는 걸 생각해줘야 함. -> 그냥 이동 보다 먼저 시켜줘야 함.
- 순간이동을 했을 때 동생까지의 거리가 더 멀어지면, 그 경우는 최선의 경우가 아니라 제외.
 */
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, K;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int vis[100'001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    vis[N] = 1;
    pq.emplace(vis[N],N);
    while(!pq.empty()){
        int cur = pq.top().Y; pq.pop();
        // cout << cur << "(" << vis[cur] << ")" << " -> ";

        if(cur == K) {
            cout << vis[cur] - 1;
            break;
        }

        for(int nxt: {cur * 2, cur - 1, cur + 1}){
            if(nxt < 0 || nxt > 100'000 || vis[nxt] != 0) continue;
            if(nxt == cur * 2){
                // 거리가 더 멀어지면 조기 종료.
                int cur_distance = abs(K - cur);
                int nxt_distance = abs(K - nxt);
                if(nxt_distance >= cur_distance) continue;

                vis[nxt] = vis[cur];
                pq.emplace(vis[nxt], nxt);
            } else{
                vis[nxt] = vis[cur]+1;
                pq.emplace(vis[nxt], nxt);
            }
        }
    }

    return 0;
}