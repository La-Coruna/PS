/* 
[프린터 큐]
- date: 24.08.24
- 분류: Priority Queue
 */

#include<bits/stdc++.h>
using namespace std;

#define priority first
#define num second

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        priority_queue<pair<int,int>> max_heap;
        queue<pair<int,int>> Q;
        int N, M, priority;
        cin >> N >> M;
        for(int i = 0; i < N; i++){
            cin >> priority;
            max_heap.push({priority, i});
            Q.push({priority, i});
        }

        int answer = 1;
        while(!max_heap.empty()){
            bool isFound = false;
            int max_priority = max_heap.top().priority;
            while(!Q.empty()){
                pair<int,int> cur = Q.front();
                if(cur.priority == max_priority){
                    if(cur.num == M) {isFound = true; break;}
                    Q.pop();
                    max_heap.pop();
                    answer++;
                    break;
                }
                Q.push(cur);
                Q.pop();
            }

            if(isFound) break;
        }
        cout << answer << '\n';
    }

    return 0;
}