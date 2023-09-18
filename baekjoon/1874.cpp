/* 
[스택 수열]
- date: 0918
- 분류: stack

- 시간: 2초
- 데이터 수: 100,000
ㄴ> 사용 가능한 알고리즘은 O(n)..?

- 알고리즘: 만들어진 수열을 완전히 반대로 행동해서 다시 1~n으로 만들것임.
- 틀린이유: answer = "+\n" + answer; 이런 식으로 답을 더해나갔는데, 이것이 속도가 엄청 느리더라. 그래서 시간초과 뜸. 그냥 stack을 쓰는것이 훨씬 빨랐다.
 */

#include <iostream>
#include <stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, input, next_num;
    stack<int> input_stack;
    stack<int> storage_stack;
    stack<char> answer;
    bool NO = false;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;
        input_stack.push(input);
    }    

    next_num = n;
    while(next_num){
        if(!storage_stack.empty() && storage_stack.top() == next_num){
            next_num--;
            storage_stack.pop();
            answer.push('+');
        }
        else if(!input_stack.empty()){
            storage_stack.push(input_stack.top());
            input_stack.pop();
            answer.push('-');
        }    
        else{
            NO = true;
            break;
        }
    }

    if(NO)
        cout << "NO";
    else{
        while(!answer.empty()){
            cout << answer.top() << "\n";
            answer.pop();
        }
    }

    return 0;
}