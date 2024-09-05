/* 
[최대 힙]
- date: 24.09.05
- 분류: priority queue, heap
 */
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int> pq;

    int N;
    cin >> N;
    while(N--){
        int x;
        cin >> x;
        if(x == 0){
            if(pq.empty())
                cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(x);
    }
    return 0;
}