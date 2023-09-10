/* 
[카드2]
- date: 0910
- 분류: queue
- 알고리즘: front를 삭제하거나, front를 빼서 back에 다시 삽입하는 것은 queue를 사용하는 것이 용이
 */

#include <iostream>
#include <queue>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    queue<int> cards;
    for(int i = 1; i <= N; i++){
        cards.push(i);
    }
    for(int i = 1; i < N; i++){
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }

    cout << cards.front();

    return 0;
}
