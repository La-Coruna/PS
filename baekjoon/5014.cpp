/* 
[스타트링크]
- date: 24.06.29
- 분류: BFS
- S==G인 경우도 생각해주자.
 */
#include <bits/stdc++.h>
using namespace std;
int vis[1000003];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int F, S, G, U, D, answer;
    bool isArrived = false;
    cin >> F >> S >> G >> U >> D;
    if(S==G){
        cout << 0; return 0;
    }
    queue<int> Q;
    Q.push(S);
    vis[S] = 1; // 시작값이 1임을 주의.
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int next : {cur + U, cur - D}){
            if(next < 1 || next > F) continue;
            if(vis[next]>0) continue;
            if(next == G){
                isArrived = true;
                answer = vis[cur];
                break;
            }
            vis[next] = vis[cur] + 1;
            Q.push(next);
        }
        if(isArrived) break;
    }
    if(isArrived)
        cout << answer;
    else
        cout << "use the stairs";
    return 0;
}