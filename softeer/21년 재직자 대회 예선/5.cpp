/* 
[21년 재직자 대회 예선] 마이크로서버
- date: 24.09.11
- tag: greedy, priority queue
- url: https://softeer.ai/class/devcrew/study/resource/detail/description/6264?id=280&resourceId=328
 */
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int N, arr[100'000];
        priority_queue<int> pq;
        pq.emplace(900);
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        sort(arr,arr+N,greater<int>());
        for(int i = 0; i < N; i++){
            int max_remained_storage = pq.top();
            if(max_remained_storage >= arr[i]){
                pq.pop();
                pq.emplace(max_remained_storage - arr[i]);
            } else{
                pq.emplace(900 - arr[i]);
            }
        }
        cout << pq.size() << '\n';
    }

    return 0;
}