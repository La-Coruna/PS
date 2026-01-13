/*
[가운데를 말해요] 
- date: 26.01.13

- N = 100'000 = 10^5
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<int> left; // left.top()이 중간값
    priority_queue<int,vector<int>,greater<int>> right;

    for(int i = 0; i < N; i++){
        int cur;
        cin >> cur;

        // 중간값보다 작으면 왼쪽, 크면 오른쪽에 보낼 것임
        if(left.empty() || cur <= left.top()) left.emplace(cur);
        else right.emplace(cur);

        // 크기가 불균형 해지면 조정. 왼쪽이 한 더 많아도 됨.
        if(left.size() < right.size()){
            left.emplace(right.top());
            right.pop();
        }
        else if(left.size() > right.size()+1){
            right.emplace(left.top());
            left.pop();
        }
        cout << left.top() << '\n';
    }

    return 0;
}