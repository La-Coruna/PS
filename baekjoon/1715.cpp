/* 
[카드 정렬하기]
- date: 24.08.04
- 분류: priority queue
 */
#include <bits/stdc++.h>
using namespace std;

class cmp{
public:
    bool operator() (int a, int b){
        if(abs(a) != abs(b)) return abs(a) > abs(b);
        return a > 0 && b < 0;
    }
};

int N, input;
priority_queue<int, vector<int>, cmp> Q;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        Q.push(input);
    }

    int answer = 0;
    while(!Q.empty()){
        int left_card, right_card, merged_card;
        left_card = Q.top(); Q.pop();
        if(Q.empty()) break;
        right_card = Q.top(); Q.pop();
        merged_card = left_card + right_card;
        answer += merged_card;
        Q.push(merged_card);
    }

    cout << answer;
    return 0;
}