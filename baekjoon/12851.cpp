/*
[숨바꼭질 2] 
- date: 26.04.17

가장 빠른 시간
가장 빠른 시간으로 찾는 방법

0 ≤ N,K ≤ 100,000

x-1, x+1, 2*x

K가 100,000에 있으면, 수빈이는 99'999, 100'001, 50'000에서 갈 수 있음.
즉 수빈이는 100'001을 넘어서 갈 필요 없음
*/
#include <bits/stdc++.h>
using namespace std;

int N, K;
queue<int> Q;
int vis[100'001], cnt[100'001], min_dist = 100'001; // cnt는 이전 노드에서 올 수 있는 방법 수

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    vis[N] = 1;
    cnt[N] = 1;
    Q.emplace(N);    

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        int arr[] = {cur-1,cur+1,2*cur};
        for(int nxt: arr){
            if(nxt < 0 || nxt > 100'000) continue;
            
            // 1. 처음 방문한 경우
            if(vis[nxt] == 0){
                vis[nxt] = vis[cur]+1;
                cnt[nxt] = cnt[cur];
                // 1-1. 도착 지점인 경우, 추가 탐색 X
                if(nxt == K) min_dist = vis[nxt];
                // 1-2. 그외의 경우, 최단 거리를 초과하게 될 것들은 Q에 안 넣음.
                if(vis[nxt] < min_dist) Q.emplace(nxt);
            }

            // 2. 이미 방문했던 곳이지만, 지금 온 거리가 기존에 왔던 거리랑 같은 경우, cnt 추가해주기
            else if(vis[cur]+1 == vis[nxt]) cnt[nxt] += cnt[cur];
        }
    }

    cout << vis[K]-1 << '\n' << cnt[K];

    return 0;
}