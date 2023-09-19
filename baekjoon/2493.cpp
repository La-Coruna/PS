/* 
[탑]
- date: 0918
- 분류: stack

- 시간: 1.5초
- 데이터 수: 500,000
ㄴ> 사용 가능한 알고리즘은 O(n)..?

- 알고리즘: 6 9 5 7 4 >> 오른쪽부터 스택에 길이랑 인덱스를 저장하고, 다음 송전탑이랑 비교해서 정답을 기록한다.
            스택에는 신호를 송신했지만 아직 수신 받지 못한 송전탑들이 저장되고,
            스택에서 하나 씩 꺼내서 이번 송전탑에서 수신 받을 수 있는지 검사한 다음에,
            스택에서 막 꺼낸 송전탑이 이번 송전탑에서 수신을 못하면, 스택에 남아있는 다른 송전탑 모두가 이번 송전탑에서 수신 못받는 것임.
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    int N, input;
    stack<int> input_stack;
    stack<int> length_storage_stack;
    stack<int> index_storage_stack;

    cin >> N;
    vector<int> answer(N+1,0); // 0번 칸은 버릴 거임.
    for(int i = 0; i < N; i++){
        cin >> input;
        input_stack.push(input);
    }

    while(N){
        length_storage_stack.push(input_stack.top()); // 송전탑 길이 저장
        index_storage_stack.push(N--); // 송전탑 인덱스 저장
        input_stack.pop();
        while(!input_stack.empty() && !length_storage_stack.empty() && input_stack.top() > length_storage_stack.top()){
            answer[index_storage_stack.top()] = N; // 송전탑 인덱스에 입력
            length_storage_stack.pop();
            index_storage_stack.pop();
        }

    }

    for(vector<int>::iterator itr = answer.begin()+1; itr != answer.end(); itr++){
        cout << *itr << " ";
    }

    return 0;
}