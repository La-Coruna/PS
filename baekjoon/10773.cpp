/* 
[제로]
- date: 0917
- 분류: stack

- 시간: 1초
- 데이터 수: 100000
ㄴ> 사용 가능한 알고리즘은 O(n)
 */
#include <iostream>
#include <stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, input;
    int res = 0;
    stack<int> s;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        if(input == 0)
            s.pop();
        else
            s.push(input);
    }
    while(!s.empty()){
        res += s.top();
        s.pop();
    }
    
    cout << res;

    return 0;
}