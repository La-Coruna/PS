/* 
[절댓값 힙]
- date: 24.09.08
- 분류: heap, priority_queue
 */
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<pair<int,bool>,
            vector<pair<int,bool>>,
            greater<pair<int,bool>>> pq;
    int N, x;

    cin >> N;
    while(N--){
        cin >> x;
        if(x == 0){
            if(pq.empty()) {
                cout << 0 << '\n';
                continue;
            }
            auto cur = pq.top();
            if(cur.Y) cout << cur.X << '\n';
            else cout << (-1) * cur.X << '\n';
            pq.pop();
        } else{
            if(x > 0) pq.emplace(x, true);
            else pq.emplace((-1) * x, false);
        }
    }

    return 0;
}