/* 
[21년 재직자 대회 본선] 거리 합 구하기
- date: 24.09.11
- tag: 
- url: https://softeer.ai/class/devcrew/study/resource/detail/description/6258?id=280&resourceId=328
 */
#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int,int>> adj[200000];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N-1; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(c,v);
        adj[v].emplace_back(c,u);
    }

\
    while(!Q.empty()){

    }


    return 0;
}