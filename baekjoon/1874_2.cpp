/* 
[스택 수열]
- date: 24.06.01
- 분류: stack

- 시간: 2초
- 데이터 수: 100,000
ㄴ> 사용 가능한 알고리즘은 O(n)..?
 */

#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int num;
    vector<int> arr;
    stack<int> s;
    string answer;
    bool isPossible = true;

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num;
        arr.emplace_back(num);
    }

    for(int idx = 0, i = 1; idx < n;){
        if(s.empty() || s.top() < arr[idx]){
            s.push(i);
            answer += "+\n";
            i++;
        } else if(s.top() == arr[idx]){
            s.pop();
            answer += "-\n";
            idx++;
        } else{
            answer = "NO";
            break;
        }
    }

    cout << answer;

    return 0;
}