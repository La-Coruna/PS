/*
[두 용액] 
- date: 26.01.06

- N = 10^5
- 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액의 특성값을 출력
- 용액 배열을 한번 돌면서, 현재 용액의 특성값 x에 대해서, -x를 이진 탐색으로 찾음 -> O(NlgN)

- 1. arr 정렬
- 2. n번 돌면서, x에 대해서 lower_bound로 -x 위치 찾기
- 3. (-x)위치의 좌,우 요소 중 절대값이 0에 가까운 것을 선택

*/
#include <bits/stdc++.h>
using namespace std;

#define INF 0x7f7f7f7f

int N;
vector<int> arr;

struct Answer{
    int x;
    int y;
    int absSum;

    Answer(){
        x = 0;
        y = 1;
        absSum = INF;
    }
};

Answer answer;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    arr.assign(N, 0);
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    // 1. 정렬
    sort(arr.begin(), arr.end());

    // 2. 이진 탐색으로 -x 값 찾음.
    for(int i = 0; i < N-1; i++){
        int x;
        int y, y_left, y_right;
        int absSum, leftAbsSum = INF, rightAbsSum = INF;
        x = arr[i];

        auto idx = lower_bound(arr.begin() + i+1, arr.end(), -x);

        // 이진 탐색 후 오른쪽 선택한 경우의 합
        // 오른쪽은 end()면 안됨
        if(idx != arr.end()){
            y_right = *idx;
            rightAbsSum = abs(x + y_right);
        }

        // 이진 탐색했을 때 왼쪽을 선택한 경우의 합
        // 왼쪽이 x면 안됨
        if(idx - 1 != arr.begin()+i){
            y_left = *(idx-1);
            leftAbsSum = abs(x + y_left);
        }

        // 왼쪽과 오른쪽 중 합의 절대값이 0에 더 가까운 거 선택
        if(leftAbsSum < rightAbsSum){
            y = y_left;
            absSum = leftAbsSum;
        } else {
            y = y_right;
            absSum = rightAbsSum;
        }
        
        if(absSum < answer.absSum){
            answer.x = x;
            answer.y = y;
            answer.absSum = absSum;
        }
        
        if(absSum == 0) break;
    }

    cout << answer.x << ' ' << answer.y;

    return 0;
}