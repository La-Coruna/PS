/* 
date: 24.06.03
분류: stack

인풋의 오른쪽부터 차례대로 비교하면서,
스택 안에 자신보다 작은 숫자들을 전부 뺌.
뺄 때마다 정답 스택에 인풋의 오른쪽 숫자를 넣음.
그리고 다 뺀 후, 스택에 그 숫자를 집어 넣음.
그러면 스택에는 지금 집어 넣는 숫자보다 작은 숫자는 하나도 없음을 보장할 수 있음.

나는 가장 오른쪽 탑부터 '어떤 탑이 이 탑을 수신해 주는지' 확인하면서 순회함.
하지만 반대로 왼쪽 탑부터 '이 탑이 어느 탑들을 수신해 줄 수 있는지' 확인하면서 순회하는 방법으로도 풀 수 있음.
 */

#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    stack<int> towerHeights;
    stack<int> towerIdx;
    
    cin >> N;
    vector<int> inputs(N);
    vector<int> answer(N);
    for(int i = 0; i < N; i++){
        cin >> inputs[i];
    }
    
    for(int i = N-1; i >= 0; i--){
        while(!towerHeights.empty() && inputs[i] >= towerHeights.top()){
            answer[towerIdx.top()] = i+1;
            towerHeights.pop();
            towerIdx.pop();
        }
        towerHeights.push(inputs[i]);
        towerIdx.push(i);
    }

    for(int i = 0; i < N; i++){
        cout << answer[i] << " ";
    }

    return 0;
}

/* 

// 어째선지 배열을 크게 선언하면 내 컴퓨터에서 안 돌아감;;
// 그래서 vector로 바꿔서 풀음.
// 하지만 아래도 정답. 백준에서는 잘 실행됨.

#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int inputs[500000] = {0};
    int answer[500000] = {0};
    stack<int> towerHeights;
    stack<int> towerIdx;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> inputs[i];
    }
    
    for(int i = N-1; i >= 0; i--){
        while(!towerHeights.empty() && inputs[i] >= towerHeights.top()){
            answer[towerIdx.top()] = i+1;
            towerHeights.pop();
            towerIdx.pop();
        }
        towerHeights.push(inputs[i]);
        towerIdx.push(i);
    }

    for(int i = 0; i < N; i++){
        cout << answer[i] << " ";
    }

    return 0;
}
 */