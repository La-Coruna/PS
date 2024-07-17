/* 
[텀 프로젝트]
- date: 24.07.17
- 분류: BFS
 */
#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        queue<int> Q;
        int n, answer = 0, arr[100001], vis[100001];
        fill(vis, vis+100001, 0);
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> arr[i];

        for(int i = 1; i <= n; i++){
            if(vis[i] != 0) continue;
            Q.push(i);
            vis[i] = i;
            while(!Q.empty()){
                int next = arr[Q.front()]; Q.pop();
                // vis가 i인 팀이 딱 떨어진 경우.
                if(vis[next] == i && next == i) continue;

                // 그렇지 않은 경우, i부터 팀이 못되는 사람을 찾음.
                else if (vis[next] != 0){ // circle이 아닌 부분을 짤라서 개수를 셈.
                    for(int j = i; j != next; j=arr[j]){
                        answer++;
                    }
                    continue;
                };
                vis[next] = i;
                Q.push(next);
            }
        }
        cout << answer << '\n';
    }
    return 0;
}