/*
[회전하는 큐]
- date: 24.09.17
- 분류: deque
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, arr[50];
    deque<int> Q;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        Q.push_back(i);
    }
    for(int i = 0; i < M; i++)
        cin >> arr[i];
    
    int total_cnt = 0;
    int cnt = 0;
    for(int i = 0; i < M;){
        int cur = Q.front();
        if(cur == arr[i]){
            total_cnt += min(cnt, ((int)Q.size())-cnt);
            i++;
            cnt = 0;
            Q.pop_front();
        } else{
            Q.pop_front();
            Q.push_back(cur);
            cnt++;
        }
    }

    cout << total_cnt;

    return 0;
}