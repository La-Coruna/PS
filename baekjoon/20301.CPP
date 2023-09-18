/* 
[반전 요세푸스]
- date: 0917
- 분류: QUEUE (하지만 list로 풀었죠?)
- 깨달은 점: empty일 때 itr에 begin()을 저장해두고, push_back()을 하면, itr은 end()를 가리키고 있다.

분류에는 queue쓰라고 했는데, 난 list로 풀었다...
queue로 푸는 것은, 앞에 있는 원소를 뒤로 다시 넣는 방식으로 푸나보다.
-> queue로 그래서 다시 풀어봄.
92ms에서 64ms로 속도가 개선됨.
 */

#include <iostream>
#include <deque>

using namespace std;

int main(void){
    int N,K,M,m;
    deque<int> q;
    bool isReverse = false;

    cin >> N >> K >> M;
    m = M;
    for(int i = 1; i<=N;i++){
        q.push_back(i);
    }

    while(1){
        for(int i = 1; i < K; i++){
            if(isReverse){
                q.push_front(q.back());
                q.pop_back();
            }
            else {
                q.push_back(q.front());
                q.pop_front();
            }
        }
        if(isReverse){
            cout << q.back();
            q.pop_back();
        } else{
            cout << q.front();
            q.pop_front();
        }
        if(!(--m)){
            isReverse = !isReverse;
            m=M;
        }
        if(q.empty())
            break;
        cout << "\n";
    }

    return 0;
}