/* 
[요세푸스 문제]
- date: 0917
- 분류: QUEUE (하지만 list로 풀었죠?)
- 깨달은 점: empty일 때 itr에 begin()을 저장해두고, push_back()을 하면, itr은 end()를 가리키고 있다.

분류에는 queue쓰라고 했는데, 난 list로 풀었다...
queue로 푸는 것은, 앞에 있는 원소를 뒤로 다시 넣는 방식으로 푸나보다.
 */

#include <iostream>
#include <list>

using namespace std;

int main(void){
    int N,K;
    list<int> l;
    list<int>::iterator itr;

    cin >> N >> K;

    for(int i = 1; i<=N;i++){
        l.push_back(i);
    }
    itr = l.begin();

    cout << "<";
    while(1){
        for(int i = 1; i < K; i++){
            itr++;
            if(itr==l.end())
                itr=l.begin();
        }
        cout << *itr;
        itr = l.erase(itr);
        if(l.empty())
            break;
        if(itr==l.end())
            itr=l.begin();
        cout << ", ";
    }
    cout << ">";

    return 0;
}