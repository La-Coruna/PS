/*
[A → B] 
- date: 25.01.23
- 분류: bfs
*/
#include <bits/stdc++.h>
using namespace std;

int A, B, answer = -1;
queue<long long> Q;
unordered_map<long long,int> vis;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    
    vis[A] = 1;
    Q.push(A);

    while(!Q.empty()){
        long long cur = Q.front(); Q.pop();
        for(long long nxt : {cur * 2, cur * 10 + 1}){
            if(nxt > B || vis[nxt]) continue;
            vis[nxt] = vis[cur]+1;
            if(nxt == B) {
                cout << vis[nxt];
                return 0;
            }
            Q.push(nxt);
        }
    }

    cout << answer;

    return 0;
}