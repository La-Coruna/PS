/*
[DSLR] 
- date: 26.01.22

그냥 bfs로 거리 구하면 될듯
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int A, B;
        cin >> A >> B;

        string visit[10'001];
        fill(visit, visit+10'001, "X");
        
        queue<int> Q;
        visit[A] = "";
        Q.emplace(A);

        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            int nxt;

            // D: D 는 n을 두 배로 바꾼다. (2n mod 10000)
            nxt = (cur * 2) % 10000;
            if(visit[nxt] == "X"){
                visit[nxt] = visit[cur] + "D";
                if(nxt == B) break;
                Q.emplace(nxt);
            }
            
            // S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다.
            nxt = (cur == 0) ? 9999 : cur - 1;
            if(visit[nxt] == "X"){
                visit[nxt] = visit[cur] + "S";
                if(nxt == B) break;
                Q.emplace(nxt);
            }
            
            // d1 ~ d4
            int d1 = (cur/1000) % 10, d2 = (cur/100) % 10, d3 = (cur/10) % 10, d4 = cur % 10;
            
            // L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. d2, d3, d4, d1
            nxt = d2*1000 + d3*100 + d4*10 + d1;
            if(visit[nxt] == "X"){
                visit[nxt] = visit[cur] + "L";
                if(nxt == B) break;
                Q.emplace(nxt);
            }
            
            // R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. d4, d1, d2, d3
            nxt = d4*1000 + d1*100 + d2*10 + d3;
            if(visit[nxt] == "X"){
                visit[nxt] = visit[cur] + "R";
                if(nxt == B) break;
                Q.emplace(nxt);
            }
        }

        cout << visit[B] << '\n';
    }

    return 0;
}